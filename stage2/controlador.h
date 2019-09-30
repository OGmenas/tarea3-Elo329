#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include "DetectorDeRequerimientos.h"
#include "SemaforoP.h"

class controlador
{
private:
    SemaforoP * semp;
    DetectorDeRequerimientos * boton;
    int tiempo;

public:
    controlador(SemaforoP * semP, DetectorDeRequerimientos * btn);
    void manageTraffic();
};


#endif