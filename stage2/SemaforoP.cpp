 #include "SemaforoP.h"

SemaforoP::SemaforoP(int gt, int tt):TrafficLight(gt,tt)
{
    state = 0;    
}

void SemaforoP::turnGreenLightOn()
{
    state = 2;
}

void SemaforoP::turnGreenLightOff()
{
    state = 1;
}

void SemaforoP::turnRedLightOn()
{
    state = 0;
}

int SemaforoP::getBlinkingTime()
{
    return TrafficLight::getTransitionTime();
}

int SemaforoP::getGreenLightTime()
{
    return TrafficLight::getGreenTime();
}

string SemaforoP::ToString()
{
    switch (state)
    {
    case 0:
        return "R";
    case 1:
        return "B";    
    case 2:
        return "V";
    default:
        return "caso general";
    }
}

// ostream& operator << (ostream &o, const SemaforoP &semp)
// {

// }