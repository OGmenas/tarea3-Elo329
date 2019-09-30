#include "MyTimer.h"
#include "controlador.h"
#include "SimuladorDeEntradas.h"

int main(int argc, char* argv[])
{
    DetectorDeRequerimientos* boton = new DetectorDeRequerimientos();
    SimuladorDeEntradas* simulador = new SimuladorDeEntradas(boton, argv[1]);
    SemaforoP* peatonal = new SemaforoP(3,3);
    controlador controlador(peatonal,boton);
    MyTimer timer(1000,*simulador);
    controlador.manageTraffic();
}
