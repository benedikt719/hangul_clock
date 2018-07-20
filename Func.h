#ifndef Func_h
#define Func_h


#include "Arduino.h"

class Func {
  public:
  	void Setup();
    void FilterHour(int Hour);
    void FilterMin(int Minute);
};

#endif
