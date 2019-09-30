#include "SimuladorDeEntradas.h"
#include<fstream>
#include<iostream>

using namespace std;

SimuladorDeEntradas::SimuladorDeEntradas(DetectorDeRequerimientos * btn, char * file)
{
    filename = file;
    boton = btn;
    cant_entradas = 0;
}

void SimuladorDeEntradas::actionPerformed()
{   
    ifstream filebuffer;
    filebuffer.open(filename);
    string tmp;
    for(int i=0; i <= cant_entradas;i++)
    {
        if(getline(filebuffer,tmp))
        {
            if(tmp == "1" && cant_entradas == i)
            {
                cout<< "requerimiento boton"<<endl;
                boton->setOn();
            }
        }
        else
        {
            exit(0);
        }
    }
    cant_entradas++;
}