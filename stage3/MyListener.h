#include "Listener.h"
class MyListener:public Listener {
public:
   MyListener();
   void actionPerformed();
private:
   int i;
};