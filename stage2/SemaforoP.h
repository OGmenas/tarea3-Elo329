#ifndef SEMAFOROP_H_
#include "TrafficLight.h"

class SemaforoP : public TrafficLight
{
private:
    int state;
    int greenTime;
    int transitionTime;

public:
    SemaforoP();
    SemaforoP(int greenTime, int blinkingTime);
    void turnRedLightOn();
    void turnGreenLightOn();
    void turnGreenLightOff();
    int getGreenLightTime();
    int getBlinkingTime();
    string ToString();
};

#endif