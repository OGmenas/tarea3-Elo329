#if !defined MY_TIMER_H
#define MY_TIMER_H
#include "Listener.h"

#include <thread>
using namespace std;
class MyTimer: public thread {
public:
   MyTimer(int period, Listener &listener);
   void resume();
   void pause();
   bool isRunning();
   void stop();
   friend void concurrentTask(MyTimer *t);
private:
   int period;
   bool running, done;
   Listener &listener;
};
#endif