#include "../firmware/adaptive.h"
#include <cassert>
#include <limits>
int main(){
 Adaptive a;a.tick(0,true,true,40);assert(!a.relay&&a.today[0]==0);
 a.tick(60000,true,true,40);assert(a.relay&&a.today[0]==1);
 a.tick(60001,false,true,40);a.tick(69999,false,true,40);assert(a.relay);
 a.tick(70000,false,true,40);assert(!a.relay);
 a.tick(71000,true,true,40);assert(a.today[0]==2);a.tick(71001,false,true,40);
 a.tick(86460000,true,true,40);assert(a.previous[0]==2&&a.hold==60000&&a.relay);
 a.tick(86460001,false,true,40);a.tick(86519999,false,true,40);assert(a.relay);
 a.tick(86520000,false,true,40);assert(!a.relay);
 a.tick(86520100,true,true,500);assert(a.latched&&!a.relay&&!a.reset());
 a.tick(86520200,true,true,40);assert(a.latched&&!a.relay);assert(a.reset());
 a.tick(86520300,false,false,0);assert(a.latched&&!a.relay);
 a.tick(86520400,false,true,std::numeric_limits<float>::quiet_NaN());assert(!a.valid&&!a.reset());
 a.tick(86520500,false,true,-1);assert(!a.valid);
 a.tick(86520600,false,true,0);assert(a.reset());a.stop();assert(a.latched);
 a.tick(4u*86400000u,false,true,0);assert(a.previous[0]==0);
 Adaptive w;w.tick(0xfffffff0u,false,true,0);w.tick(59984,true,true,40);assert(w.elapsed==60000&&w.relay);
 w.today[0]=65535;w.tick(59985,false,true,40);w.tick(59986,true,true,40);assert(w.today[0]==65535);
}
