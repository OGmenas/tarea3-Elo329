#include "TrafficLight.h"


TrafficLight::TrafficLight(int redTime)
{
    this->redTime = redTime;
    this->greenTime=3;
    this->yellowTime=3;
    this->state = 0;

}
void TrafficLight::turnRed()
{
    this->state = 0;
}

void TrafficLight::turnGreen()
{
    this->state = 2;
}

void TrafficLight::turnTransition()
{
    this->state = 1;
}

int TrafficLight::getGreenTime()
{
    return greenTime;
}
int TrafficLight::getRedTime()
{
    return redTime;
}
int TrafficLight::getState()
{
    return state;
}
int TrafficLight::getTransitionTime()
{
    return yellowTime;
}
