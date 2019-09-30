#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include "DetectorDeRequerimientos.h"
#include "SemaforoP.h"
#include "StreetTrafficLight.h"
#include "SemaforoG.h"


class controlador
{
private:
    SemaforoP * sempA;
	SemaforoP * sempB;
	DetectorDeRequerimientos * sensor;
	DetectorDeRequerimientos * boton;
	StreetTrafficLight * semaf1;
	SemaforoG * semaf2;
	StreetTrafficLight * semaf3;
	SemaforoG * semaf4;
	StreetTrafficLight * semaf5;
	int tiempo = 0;
    // int greenTimeSemPA;
	// int greenTimeSemPB;
	// int greenTimeSemaforo1;
	// int greenTimeSemaforo2;
	// int greenTimeSemaforo3;
	// int greenTimeSemaforo4;
	// int greenTimeSemaforo5;
	// int yellowTimeSemaforo1;
	// int yellowTimeSemaforo3;
	// int yellowTimeSemaforo5;
	// int transitionTimeSemapA;
	// int transitionTimeSemapB;
	// int transitionTimeSemaf2;
	// int transitionTimeSemaf4;

public:
    controlador(SemaforoP * semPA,SemaforoP *semPB,StreetTrafficLight * semaforo1,SemaforoG * semaforo2, StreetTrafficLight * semaforo3
    ,SemaforoG * semaforo4,StreetTrafficLight *semaforo5,DetectorDeRequerimientos * btn, DetectorDeRequerimientos * sensor);
    void matrizCasos();
	void manageTraffic();

};


#endif