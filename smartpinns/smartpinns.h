#include "Arduino.h"

#ifndef smartpinns_h
#define smartpinns_h

void out(int* start, int* stop);
void in(int start, int stop);
void in_pl(int start, int stop);

int readPin(int index);
int readPin_pl(int index);
int getPin(int index);
#endif