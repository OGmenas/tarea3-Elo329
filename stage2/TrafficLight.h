#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

#include<iostream>

using namespace std;


class TrafficLight
{
private:

    int redTime;
    int state;
    int yellowTime;
    int greenTime;
public:
    TrafficLight(int greenTime, int yellowTime);
    void turnRed();
    void turnGreen();
    void turnTransition();
    int getGreenTime();
    int getRedTime();
    int getState();
    int getTransitionTime();

};

#endif