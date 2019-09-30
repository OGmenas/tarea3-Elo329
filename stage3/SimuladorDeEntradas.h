#ifndef SIMULADORDEENTRADAS_H_
#define SIMULADORDEENTRADAS_H_
#include "DetectorDeRequerimientos.h"
#include "Listener.h"
#include<string>

using namespace std;
class SimuladorDeEntradas : public Listener
{
private:
    DetectorDeRequerimientos * sensor;
    char* filename;


public:
    SimuladorDeEntradas(DetectorDeRequerimientos * sensorInductivo , char* file);
    void actionPerformed();

};


#endif