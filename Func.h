#ifndef Func_h
#define Func_h


#include "Arduino.h"

class Func {
  public:
  	int NumberList[];// 시간 2진 데이터 시프트레지스터용

  	NumberList[0]
  	//보기 좋게 만드는 걸 생각하기 


  	
  	void ledOn(int Leds);
    void FilterHour(int Hour);
    void FilterMin(int Minute);
};

#endif
