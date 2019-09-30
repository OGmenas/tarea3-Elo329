#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include "DetectorDeRequerimientos.h"
#include "SemaforoG.h"

class controlador
{
private:
    SemaforoG * semg;
    DetectorDeRequerimientos * sensor;
    int tiempo;

public:
    controlador(SemaforoG * semG, DetectorDeRequerimientos * sensor);
    void manageTraffic();
};


#endif