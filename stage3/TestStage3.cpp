#include "controlador.h"
#include "SimuladorDeEntradas.h"
#include "MyTimer.h"

#include<iostream>

using namespace std;

int main (int argc, char* argv[])
{
    DetectorDeRequerimientos* sensor = new DetectorDeRequerimientos();
    SimuladorDeEntradas* simulador= new SimuladorDeEntradas(sensor, argv[1]);
    SemaforoG* giro = new SemaforoG(3,3);
    controlador controlador(giro,sensor);
    MyTimer timer (1000, *simulador);
    controlador.manageTraffic();
    
}