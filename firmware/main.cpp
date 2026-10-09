#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include "adaptive.h"
Adaptive rule;Adafruit_INA219 ina(0x40);bool sensorPresent=false;
uint32_t lastSample=0,lastReport=0,lastProbe=0;String command;
void setup(){Serial.begin(115200);pinMode(2,INPUT);pinMode(5,OUTPUT);digitalWrite(5,LOW);Wire.begin();sensorPresent=ina.begin();rule.tick(millis(),false,false,0);}
void loop(){
 uint32_t now=millis();
 if(!sensorPresent&&uint32_t(now-lastProbe)>=5000){lastProbe=now;sensorPresent=ina.begin();}
 if(uint32_t(now-lastSample)>=100){
  lastSample=now;Wire.beginTransmission(0x40);bool ack=Wire.endTransmission()==0;
  float ma=sensorPresent&&ack?ina.getCurrent_mA():NAN;
  float volts=sensorPresent&&ack?ina.getBusVoltage_V():NAN;
  bool valid=sensorPresent&&ack&&isfinite(volts)&&volts>=0&&volts<=6;
  rule.tick(now,digitalRead(2)==HIGH,valid,ma);digitalWrite(5,rule.relay?HIGH:LOW);
 }
 while(Serial.available()){
  char c=Serial.read();if(c=='\n'){command.trim();if(command=="RESET")rule.reset();else rule.stop();digitalWrite(5,LOW);command="";}
  else if(c!='\r'){command+=c;if(command.length()>16){rule.stop();digitalWrite(5,LOW);command="";}}
 }
 if(uint32_t(now-lastReport)>=1000){
  lastReport=now;Serial.print("{\"id\":20,\"elapsed_s\":");Serial.print((unsigned long)(rule.elapsed/1000));
  Serial.print(",\"day\":");Serial.print((unsigned long)rule.day);Serial.print(",\"hour\":");Serial.print(rule.hour);
  Serial.print(",\"motion\":");Serial.print(rule.motion?"true":"false");Serial.print(",\"valid\":");Serial.print(rule.valid?"true":"false");
  Serial.print(",\"current_ma\":");if(rule.valid)Serial.print(rule.current,2);else Serial.print("null");
  Serial.print(",\"relay\":");Serial.print(rule.relay?"true":"false");Serial.print(",\"latched\":");Serial.print(rule.latched?"true":"false");
  Serial.print(",\"previous_count\":");Serial.print(rule.previous[rule.hour]);Serial.print(",\"today_count\":");Serial.print(rule.today[rule.hour]);
  Serial.print(",\"hold_ms\":");Serial.print(rule.hold);Serial.println("}");
 }
}
