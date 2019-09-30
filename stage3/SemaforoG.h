#ifndef SEMAFOROG_H_
#define SEMAFOROG_H_    

#include "TrafficLight.h"


class SemaforoG: public TrafficLight
{
private:
    int greenTime;
    int transitionTime;
    int state;
public:
    SemaforoG(int gt, int tt);
    void turnGreenLightOn();
    void turnGreenLightOff();
    void turnRedLightOn();
    int getGreenLightTime();
    int getTransitionTime();
    string ToString();

};

#endif
