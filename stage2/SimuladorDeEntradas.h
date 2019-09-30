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
    DetectorDeRequerimientos * boton;
    char* filename;
    ifstream filebuffer;

public:
    SimuladorDeEntradas(DetectorDeRequerimientos * boton , char* filename);
    void actionPerformed();
};


#endif