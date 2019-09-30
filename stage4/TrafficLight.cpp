#include "TrafficLight.h"


TrafficLight::TrafficLight(int greenTime, int yellowTime)
{
    this->redTime = 3;
    this->greenTime= greenTime;
    this->yellowTime= yellowTime;
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
