#include "SimuladorDeEntradas.h"
#include<fstream>
#include<iostream>
#include<unistd.h>

using namespace std;

SimuladorDeEntradas::SimuladorDeEntradas(DetectorDeRequerimientos * btn, char * file)
{
    filename = file;
    boton = btn;
}

void SimuladorDeEntradas::actionPerformed()
{   
    ifstream filebuffer;
    filebuffer.open(filename);
    string tmp;
    while(!filebuffer.eof())
    {
        getline(filebuffer,tmp);
        if(tmp == "1")
        {
            cout<< "requerimiento del boton "<<endl;
            boton->setOn();
        }    
        else if( tmp == "0")
            cout<<"boton apagado "<<endl;
            // if(boton->isON())
            //     boton->setOff();
        sleep(1);          
    }
    
    cout<<"lei todo el archivo"<<endl;
    exit(0);
}