#include "SemaforoG.h"

SemaforoG::SemaforoG(int gt, int tt):TrafficLight(gt,tt)
{
    state = 0;
};

int SemaforoG::getGreenTime()
{
    return TrafficLight::getGreenTime();
}
int SemaforoG::getTransitionTime()
{
    return TrafficLight::getTransitionTime();
}
void SemaforoG::turnGreenLightOn()
{
    state = 2;
}
void SemaforoG::turnGreenLightOff()
{
    state = 1;
}
void SemaforoG::turnRedLightOn()
{
    state = 0;
}

 
string SemaforoG::ToString()
{
    switch (state)
    {
    case 0:
        return "R";
    case 1:
        return "T";
    case 2:
        return "V";
    default:
        return "default";
    }
}