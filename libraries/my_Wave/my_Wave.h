#ifndef my_Wave_h

#define my_Wave_h

#include <arduino.h>

#define Trig 48
#define Echo 49

class my_Wave{
    public:
        my_Wave(int pin0,int pin1);
        int getDistance();
};

#endif