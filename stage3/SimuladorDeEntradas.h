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
    DetectorDeRequerimientos * sensor;
    char* filename;
    ifstream filebuffer;


public:
    SimuladorDeEntradas(DetectorDeRequerimientos* sensorInductivo , char* file);
    void actionPerformed();

};


#endif