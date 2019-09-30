#include "SimuladorDeEntradas.h"
#include<fstream>
#include<iostream>
#include<unistd.h>

using namespace std;

SimuladorDeEntradas::SimuladorDeEntradas(DetectorDeRequerimientos * sensorInductivo, char * file)
{
    filename = file;
    sensor = sensorInductivo;
    filebuffer.open(filename);

}

void SimuladorDeEntradas::actionPerformed()
{   

    string tmp;
    if(!filebuffer.eof())
    {
        getline(filebuffer,tmp);
        if(tmp == "1")
        {
        //    cout<< "requerimiento del sensor "<<endl;
            sensor->setOn();
        }    
        // else if( tmp == "0")
        //     cout<<"sensor inactivo "<<endl;
        //     // if(sensor->isON())
        //     //     sensor->setOff();      
    }
    else
    {
            filebuffer.close();
            cout<<tmp<<endl;
            cout<<"lei todo el archivo "<<endl;
            exit(0);
    }
      
}