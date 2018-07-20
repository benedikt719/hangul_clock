#include"Arduino.h"
#include"Func.h"

void Func::Setup(){

    for(int i=0;i<=13;i++){
      pinmode(i,OUTPUT);
    }



}

void Func::FilterHour(int Hour){

  int a = 1;
  int Hour1 = 0;
  
  if (Hour >= 12){
    Hour1 = Hour - 12;
    Serial.println("지금은 오후 ");
  }////오후 표시 led 점등

  else{
    Serial.println("지금은 오전 ");
    Hour1 = Hour;
  }

  switch (Hour1) {
    ///pinmode led 점등 부분 // 나중에 라이브러리로 작성
    case 0:
     Serial.println("12시 ");
      break;
    case 1:
      Serial.println("1시 ");
      break;
    case 2:
      Serial.println("2시 ");
      break;
    case 3:
      Serial.println("3시 ");
      break;
    case 4:
      Serial.println("4시 ");
      break;
    case 5:
      Serial.println("5시 ");
      break;
    case 6:
      Serial.println("6시 ");
      break;
    case 7:
      Serial.println("7시 ");
      break;
    case 8:
      Serial.println("8시 ");
      break;
    case 9:
      Serial.println("9시 ");
      break;
    case 10:
      Serial.println("10시 ");
      break;
    case 11:
      Serial.println("11시 ");
      break;
    case 12:
      Serial.println("12시 ");
      break;
  }
}

void Func::FilterMin(int Minute){
  int Minute_D = 0;
  int Minute_M = Minute;

  if (Minute >= 10){

    Minute_D = Minute / 10 ;
    Minute_M = Minute % 10 ;
    ///십분이상 십의자리 분을 나타내주는 부분
  }
  
  switch (Minute_D){
    case 0:
      break;
    case 1:
      Serial.println("십 ");
      break;
    case 2:
      Serial.println("이십 ");
      break;
    case 3:
      Serial.println("삼십 ");
      break;
    case 4:
      Serial.println("사십 ");
      break;
    case 5:
      Serial.println("오십 ");
      break;
  }
  switch (Minute_M){
    case 0:
      break;
    case 1:
      Serial.println("일분\n");
      break;
    case 2:
      Serial.println("이분\n");
      break;
    case 3:
      Serial.println("심분\n");
      break;
    case 4:
      Serial.println("사분\n");
      break;
    case 5:
      Serial.println("오분\n");
      break;
    case 6:
      Serial.println("육분\n");
      break;
    case 7:
      Serial.println("칠분\n");
      break;
    case 8:
      Serial.println("팔분\n");
      break;
    case 9:
      Serial.println("구분\n");
      break;

  }
}





