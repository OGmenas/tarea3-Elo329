#include "controlador.h"

#include<unistd.h>

controlador::controlador(SemaforoG * semG , DetectorDeRequerimientos * sensor)
{
    semg = semG;
    sensor =  sensor;
    tiempo = 0;
   

}

void controlador::manageTraffic()
{
        while(true)
        {   
            cout<<"aun no entro "<<endl;
            if (sensor->isON())
            {
                cout<< "capto una entrada "<<endl;
                semg->turnGreenLightOn();
                for (int i = 0; i < semg->getGreenTime(); i++)
                {
                    cout<< tiempo << "  " << semg->ToString()<<endl;
                    sleep(1);
                    tiempo++;
                }
                for (int i = 0; i < semg->getTransitionTime(); i++)
                {
                    semg->turnGreenLightOff();
                    cout<< tiempo << "  " <<semg->ToString()<<endl;
                    semg->turnGreenLightOn();
                    sleep(1);
                    tiempo++;
                }
                semg->turnGreenLightOff();
                semg->turnRedLightOn();
                cout<<tiempo<<"  "<<semg->ToString()<<endl;
                sleep(1);
                tiempo++;
                sensor->setOff();
                
                
            }
            else
            {
                cout<<"no capto nada"<<endl;
                cout<<tiempo<<"  "<<semg->ToString()<<endl;
                sleep(1);
                tiempo++;
            }
            
            
            
        }
    
};