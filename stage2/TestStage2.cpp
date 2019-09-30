#include "MyTimer.h"
#include "controlador.h"
#include "SimuladorDeEntradas.h"

int main(int argc, char* argv[])
{
    DetectorDeRequerimientos boton;
    SimuladorDeEntradas simulador(&boton, argv[1]);
    SemaforoP peatonal(3,3);
    controlador controlador(&peatonal,&boton);
    MyTimer timer(1000,simulador);
    controlador.manageTraffic();
}