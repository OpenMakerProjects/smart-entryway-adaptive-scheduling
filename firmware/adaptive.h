#pragma once
#include <cstdint>
#include <cmath>
struct Adaptive {
 uint16_t today[24]={},previous[24]={};
 uint64_t elapsed=0,lastSeen=0;uint32_t lastMillis=0;
 bool started=false,lastMotion=false,relay=false,latched=false,valid=false,motion=false;
 float current=0;unsigned hour=0;uint64_t day=0;uint32_t hold=10000;
 void tick(uint32_t now,bool detected,bool sensorValid,float ma){
  if(!started){started=true;lastMillis=now;}
  elapsed+=uint32_t(now-lastMillis);lastMillis=now;
  uint64_t newDay=elapsed/86400000ULL;
  if(newDay!=day){for(int i=0;i<24;i++){previous[i]=newDay==day+1?today[i]:0;today[i]=0;}day=newDay;}
  hour=(elapsed/3600000ULL)%24;hold=previous[hour]>=2?60000:10000;
  motion=detected;current=ma;valid=sensorValid&&std::isfinite(ma)&&ma>=0;
  if(!valid||ma>=500)latched=true;
  bool warmed=elapsed>=60000;
  if(warmed&&motion&&!lastMotion&&today[hour]<65535)++today[hour];
  if(warmed&&motion)lastSeen=elapsed;
  lastMotion=warmed&&motion;
  relay=warmed&&!latched&&valid&&(motion||(lastSeen>=60000&&elapsed-lastSeen<hold));
 }
 void stop(){latched=true;relay=false;}
 bool reset(){if(valid&&current<500){latched=false;relay=false;lastSeen=0;return true;}return false;}
};
