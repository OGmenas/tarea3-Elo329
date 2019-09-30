#include "StreetTrafficLight.h"

#include <stdlib.h>
#include <unistd.h>


using namespace std;

int main(int argc ,char* argv[])
{
    int N = strtof(argv[1],NULL);
    int redTime = strtof(argv[2],NULL);
    StreetTrafficLight sem1 (redTime);
    int gt = sem1.getGreenTime();
    int tt = sem1.getTransitionTime();
    int tiempo = 0;

   
        for (int i = 0; i < N; i++)
        {
            sem1.turnGreen();
            cout<<"Tiempo: "<<tiempo<<" [s]     "<<sem1.toString()<<endl;
            tiempo+=sem1.getGreenTime();
            sleep(sem1.getGreenTime());
            sem1.turnTransition();
            cout<<"Tiempo: "<<tiempo<<" [s]     "<<sem1.toString()<<endl;
            tiempo+=sem1.getTransitionTime();
            sleep(sem1.getTransitionTime());
            sem1.turnRed();
            cout<<"Tiempo: "<<tiempo<<" [s]     "<<sem1.toString()<<endl;
            tiempo+=sem1.getRedTime();
            sleep(sem1.getRedTime());
        }
        
   
    
}