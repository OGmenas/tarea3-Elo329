#include "SimuladorDeEntradas.h"
#include<fstream>
#include<iostream>
#include<unistd.h>

using namespace std;

SimuladorDeEntradas::SimuladorDeEntradas(DetectorDeRequerimientos * sensorInductivo, char * file)
{
    filename = file;
    sensor = sensorInductivo;
    int cant_entradas=0;

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
            cout<< "requerimiento del sensor "<<endl;
            sensor->setOn();
        }    
        else if( tmp == "0")
            cout<<"sensor inactivo "<<endl;
            // if(sensor->isON())
            //     sensor->setOff();
        sleep(1);          
    }
    
    cout<<"lei todo el archivo"<<endl;
    exit(0);    
    // ifstream filebuffer;
    // string tmp;
    // filebuffer.open(filename);
    // while(!filebuffer.eof())
    // {
    //     getline(filebuffer,tmp);
    //     if(tmp == "1")
    //     {
    //     cout<< "requerimiento del sensor "<<endl;
    //     sensor->setOn();
    //     }    
    //     else if( tmp == "0")
    //         cout<<"sensor apagado "<<endl;
    //         // if(boton->isON())
    //         //     boton->setOff();          
    // }
    // cout<<"lei todo el archivo"<<endl;
    // exit(0);
}