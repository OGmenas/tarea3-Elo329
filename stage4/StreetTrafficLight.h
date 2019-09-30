#ifndef STREETTRAFFICLIGHT_H_
#define STREETTRAFFICLIGHT_H_

#include "TrafficLight.h"
#include<string>

using namespace std;


class  StreetTrafficLight: public TrafficLight
{
private:
     int state;
public:
     StreetTrafficLight();
     StreetTrafficLight(int gt,int tt);
     string ToString();
};


#endif