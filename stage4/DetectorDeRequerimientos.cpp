#include "DetectorDeRequerimientos.h"

DetectorDeRequerimientos::DetectorDeRequerimientos()
{
    status = false;
}

bool DetectorDeRequerimientos::isON()
{
    return status;
}
void DetectorDeRequerimientos::setOn()
{
    status = true;
}
void DetectorDeRequerimientos::setOff()
{
    status = false;    
}
