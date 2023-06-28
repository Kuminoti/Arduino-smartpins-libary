#include "Arduino.h"

#ifndef inputlib_h
#define inputlib_h

void out(int* start, int* stop);
void in(int start, int stop);
void in_pl(int start, int stop);

int readPin(int index);
int readPin_pl(int index);
int getPin(int index);
#endif