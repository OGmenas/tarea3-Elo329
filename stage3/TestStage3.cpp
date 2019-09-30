#include "controlador.h"
#include "SimuladorDeEntradas.h"
#include "MyTimer.h"

#include<iostream>

using namespace std;

int main (int argc, char* argv[])
{
    DetectorDeRequerimientos sensor;
    SimuladorDeEntradas simulador(&sensor,argv[1]);
    SemaforoG semg(6,3);
    controlador controlador(&semg,&sensor);
    MyTimer timer (1000, simulador);
    controlador.manageTraffic();
    
}