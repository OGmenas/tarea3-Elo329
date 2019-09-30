#include "SimuladorDeEntradas.h"
#include<fstream>
#include<iostream>
#include<unistd.h>

using namespace std;

SimuladorDeEntradas::SimuladorDeEntradas(DetectorDeRequerimientos * button ,DetectorDeRequerimientos * sensorInductivo, char * file)
{
    filename = file;
    boton = button;
    sensor = sensorInductivo;
    filebuffer.open(filename);

}

void SimuladorDeEntradas::actionPerformed()
{   
    string tmp, button_signal, sensor_signal;
    if(!filebuffer.eof())
    {
        getline(filebuffer,tmp);
        button_signal=tmp[0];
        sensor_signal=tmp.back();
        if(button_signal == "1") boton->setOn();
        else if(sensor_signal == "1") sensor->setOn();
    }
    else
    {
        filebuffer.close();
        cout<<tmp<<endl;
        cout<<"lei todo el archivo "<<endl;
        exit(0);
    }
      
}