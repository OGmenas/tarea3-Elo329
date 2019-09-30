#ifndef SIMULADORDEENTRADAS_H_
#define SIMULADORDEENTRADAS_H_
#include "DetectorDeRequerimientos.h"
#include "Listener.h"
#include<string>
#include<fstream>

using namespace std;
class SimuladorDeEntradas : public Listener
{
private:
    DetectorDeRequerimientos * boton, *sensor;
    char* filename;
    ifstream filebuffer;
    int cant_entradas;

public:
    SimuladorDeEntradas(DetectorDeRequerimientos * button ,DetectorDeRequerimientos * sensorInductivo, char * file);
    void actionPerformed();
};


#endif