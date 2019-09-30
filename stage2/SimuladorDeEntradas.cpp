#include "SimuladorDeEntradas.h"
#include<fstream>
#include<iostream>
#include<unistd.h>

using namespace std;

SimuladorDeEntradas::SimuladorDeEntradas(DetectorDeRequerimientos * btn, char * file)
{
    filename = file;
    boton = btn;
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
            //cout<< "requerimiento del boton \n";
            boton->setOn();
        }    
        //else if( tmp == "0")
            //out<<"boton apagado \n";
            // if(boton->isON())
            //     boton->setOff();          
    }
    else
    {
      filebuffer.close();
      cout << tmp << endl;
      cout<<"lei todo el archivo"<<endl;
      exit(0);
    }
}
