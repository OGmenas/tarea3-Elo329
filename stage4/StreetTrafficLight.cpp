#include "StreetTrafficLight.h"



 StreetTrafficLight::StreetTrafficLight():TrafficLight(3,3) 
{
    state = 0;
}

 StreetTrafficLight::StreetTrafficLight(int gt, int tt):TrafficLight(gt ,tt)
{
    state = 0;
}
string StreetTrafficLight::ToString()
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
