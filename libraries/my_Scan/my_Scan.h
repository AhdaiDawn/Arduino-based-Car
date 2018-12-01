#ifndef my_Scan_h
#define my_Scan_h

#include<arduino.h>
#include <SoftwareSerial.h>

#define RX 13
#define TX 12


class my_Scan{
    public:
        my_Scan(int pin0,int pin1);
        char get_char();
        void clear();
};


#endif