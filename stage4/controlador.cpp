#include "controlador.h"
#include<unistd.h>

controlador::controlador(SemaforoP * semP , DetectorDeRequerimientos * btn)
{
    semp = semP;
    boton =  btn;
    tiempo = 0;
}

void controlador::manageTraffic()
{
    while(true)
    {   
        if (boton->isON())
        {
            cout<< "capto una entrada "<<endl;
            semp->turnGreenLightOn();
            for (int i = 0; i < semp->getGreenLightTime(); i++)
            {
                cout << tiempo << "  " << semp->ToString() << endl;
                sleep(1);
                tiempo++;
            }
            for (int i = 0; i < semp->getTransitionTime(); i++)
            {
                semp->turnGreenLightOff();
                cout << tiempo << "  " << semp->ToString() << endl;
                semp->turnGreenLightOn();
                sleep(1);
                tiempo++;
            }
            semp->turnGreenLightOff();
            semp->turnRedLightOn();
            cout<< tiempo << "  " << semp->ToString() << endl;
            sleep(1);
            tiempo++;
            boton->setOff();
        }
        else
        {
            cout<<tiempo<<"  "<<semp->ToString()<<endl;
            sleep(1);
            tiempo++;
        }
    //cout<< "El problema de las R es aquí mismito" << endl;
    }
};