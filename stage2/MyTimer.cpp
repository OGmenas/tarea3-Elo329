#include "MyTimer.h"
#include <chrono>
#include<iostream>
using namespace std;

void concurrentTask(MyTimer *t) {
   while (!t->done){
      this_thread::sleep_for(chrono::milliseconds(t->period));
      if (t->running)
         t->listener.actionPerformed();
   }
}
MyTimer::MyTimer(int p, Listener &lis) :
            thread(concurrentTask, this), period(p), listener(lis)   {//p in ms
   running = true;
}
void MyTimer::resume() {
   running = true;
}
void MyTimer::pause() {
   running = false;
}
bool MyTimer::isRunning() {
   return running;
}
void MyTimer::stop(){
   done=true;
}
