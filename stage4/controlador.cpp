#include "controlador.h"
#include<unistd.h>

controlador::controlador(SemaforoP * semPA,SemaforoP *semPB,StreetTrafficLight * semaforo1,SemaforoG * semaforo2, StreetTrafficLight * semaforo3
    ,SemaforoG * semaforo4,StreetTrafficLight *semaforo5,DetectorDeRequerimientos * btn, DetectorDeRequerimientos * sensor)
{
    boton = btn;
    sensor = sensor;
    sempA = semPA; // cruce 1 norte
    sempB = sempB; // cruce sporting
    semaf1 = semaforo1; // semaforo sporting 
    semaf2 = semaforo2; // giro a costa por sporting
    semaf3 = semaforo3; //1 norte hacia costa
    semaf4 = semaforo4; //giro a sporting por 1 norte
    semaf5 = semaforo5; // 1 norte hacia interior
    cout << "/tA/tB/t1/t2/t3/t4/t5" << endl;
}

/*
    A   B   1   2   3   4   5
A   X   0   1   1   0   1   0
B   0   X   0   0   1   1   1
1   1   0   X   1   0   0   0
2   1   0   1   X   0   1   1     
3   0   1   0   0   X   0   1                   
4   1   1   0   1   0   X   1                    
5   0   1   0   1   1   1   X                        
*/



//En esta funcion modelaremos el comportamiento de la matriz de semaforos que hay arriba
void controlador::matrizCasos()
{
        //Caso S3 y S5 en verde
    if(semaf3->getState() == 2 && semaf5->getState() == 2 && boton->isON()==false && sensor->isON()==false)
    {
        semaf3->turnTransition();
        semaf5->turnTransition();
        sempB->turnGreenLightOff();
        for (int i = 0; i < semaf5->getTransitionTime(); i++)
        {
			cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;


        }
        semaf3->turnRed();
        semaf5->turnRed();
        sempB->turnRedLightOn();
        semaf1->turnGreen();
        semaf2->turnGreenLightOn();
        
    }
        //Caso S1 y S2 en verde
    else if(semaf1->getState() == 2 && semaf2->getState()== 2 && (boton->isON()==false) && (sensor->isON()==false))
    {
        semaf1->turnTransition();
        semaf2->turnGreenLightOff();
        for (int i = 0; i < semaf1->getTransitionTime(); i++)
        {
			cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;           
        }
        
    }
        //caso S3 y S5 con boton
    else if(semaf3->getState()== 2 && semaf5->getState()== 2 && (sensor->isON()==true)&&(boton->isON()==false))
    {
        semaf5->turnTransition();
        semaf3->turnTransition();
        sempB->turnGreenLightOff();
        for (int i = 0; i < semaf5->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;    
            sleep(1);
            tiempo++;       
        }
        semaf3->turnRed();
        semaf5->turnRed();
        sempB->turnRedLightOn();
        sempA->turnGreenLightOn();
        semaf2->turnGreenLightOn();
        for (int i = 0; i < sempA->getGreenLightTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        sempA->turnGreenLightOff();
        for (int i = 0; i < sempA->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        sempA->turnRedLightOn();
        semaf1->turnGreen();
        boton->setOff();
    }

    //caso S3 y S5 con sensor
    else if(semaf3->getState()== 2 && semaf5->getState()==2 &&(sensor->isON()==true)&&(boton->isON()==false))
    {
        semaf3->turnTransition();
        sempB->turnGreenLightOff();
        for (int i = 0; i < semaf3->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;    
            sleep(1);
            tiempo++;
        }
        semaf3->turnRed();
        sempB->turnRedLightOn();
        semaf4->turnGreenLightOn();
        for (int i = 0; i < semaf4->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        semaf5->turnTransition();
        semaf4->turnGreenLightOff();
        for (int i = 0; i < semaf4->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        semaf5->turnRed();
        semaf4->turnRedLightOn();
        semaf1->turnGreen();
        semaf2->turnGreenLightOn();
        sensor->setOff();  

    }
    //Caso S1 y S2 con boton
    else if(semaf1->getState()==2 && semaf2->getState()==2 &&(boton->isON()==true)&&(sensor->isON()==false))
    {
        semaf1->turnTransition();
        for (int i = 0; i < semaf1->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;    
        }
        semaf1->turnRed();
        sempA->turnGreenLightOn();
        for (int i = 0; i < sempA->getGreenLightTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        sempA->turnGreenLightOff();
        semaf2->turnGreenLightOff();
        for (int i = 0; i < semaf2->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        sempA->turnRedLightOn();
        semaf2->turnRed();
        semaf3->turnGreen();
        sempB->turnGreenLightOn();
        semaf5->turnGreen();
        boton->setOff();
        
        
    }
    //Caso S1 y S2 con sensor
    else if(semaf1->getState()==2 && semaf2->getState()&&(sensor->isON()==true)&&(boton->isON()==false))
    {
        semaf1->turnTransition();
        semaf2->turnGreenLightOff();
        for (int i = 0; i < semaf1->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;    
        }
        semaf4->turnGreenLightOn();
        for (int i = 0; i < semaf4->getGreenTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        semaf4->turnGreenLightOn();
        for (int i = 0; i < semaf4->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        semaf4->turnRedLightOn();
        semaf3->turnGreen();
        sempB->turnGreen();
        sensor->setOff();
        
    }

    //Caso S3 y S5 con botor y sensor

    else if ( semaf3->getState()== 2 && semaf5->getState()== 2 && (boton->isON()==true)&&( sensor->isON()==true) )
    {
        semaf3->turnTransition();
        semaf5->turnTransition();
        sempB->turnGreenLightOff();
        for (int i = 0; i < semaf3->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        semaf3->turnRed();
        semaf5->turnRed();
        sempB->turnRedLightOn();
        semaf2->turnGreenLightOn();
        semaf4->turnGreenLightOn();
        sempA->turnGreenLightOn();
        for (int i = 0; i < sempA->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        semaf4->turnGreenLightOff();
        semaf2->turnGreenLightOff();
        sempA->turnGreenLightOff();
        for (int i = 0; i < sempA->getTransitionTime(); i++)
        {
        	cout << tiempo <<"\t"<< sempA->ToString()<<"\t"<< sempB->ToString()<<"\t"<< semaf1->ToString()<<"\t"<< semaf2->ToString()<<"\t"<< semaf3->ToString()<<"\t"<< semaf4->ToString()<<"\t"<< semaf5->ToString() << endl;
            sleep(1);
            tiempo++;
        }
        semaf4->turnRed();
        sempA->turnRedLightOn();
        semaf2->turnRed();
        semaf1->turnGreen();
        semaf2->turnGreenLightOn();
        sensor->setOff();
        boton->setOff();

        
        
        
    }
    
    
        

        

        
}
void controlador::manageTraffic()
{   
    matrizCasos();   
    
};