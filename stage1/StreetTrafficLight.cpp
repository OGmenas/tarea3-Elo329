#include "StreetTrafficLight.h"



 StreetTrafficLight::StreetTrafficLight():TrafficLight(3) 
{
    state = 0;
}

 StreetTrafficLight::StreetTrafficLight(int redTime):TrafficLight(redTime)
{
    state = 0;
}
string StreetTrafficLight::toString()
{
    state = TrafficLight::getState();
    switch (state)
    {
    case 0:
        return  "R";
    case 1:
        return  "A";    
    case 2:
        return "V";
    default:
        break;
    }
    return "caso general";
}
