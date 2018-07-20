#include <iostream>
using namespace std;


void FilterHour(int Hour){

	int a = 1;
	int Hour1 = 0;
	
	if (Hour >= 12){
		Hour1 = Hour - 12;
		printf("지금은 오후 ");
	}////오후 표시 led 점등

	else{
		printf("지금은 오전 ");
		Hour1 = Hour;
	}

	switch (Hour1) {
		///pinmode led 점등 부분 // 나중에 라이브러리로 작성
		case 0:
			printf("12시 ");
			break;
		case 1:
			printf("1시 ");
			break;
		case 2:
			printf("2시 ");
			break;
		case 3:
			printf("3시 ");
			break;
		case 4:
			printf("4시 ");
			break;
		case 5:
			printf("5시 ");
			break;
		case 6:
			printf("6시 ");
			break;
		case 7:
			printf("7시 ");
			break;
		case 8:
			printf("8시 ");
			break;
		case 9:
			printf("9시 ");
			break;
		case 10:
			printf("10시 ");
			break;
		case 11:
			printf("11시 ");
			break;
		case 12:
			printf("12시 ");
			break;
	}
}


void FilterMin(int Minute){
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
			printf("십 ");
			break;
		case 2:
			printf("이십 ");
			break;
		case 3:
			printf("삼십 ");
			break;
		case 4:
			printf("사십 ");
			break;
		case 5:
			printf("오십 ");
			break;
	}
	switch (Minute_M){
		case 0:
			break;
		case 1:
			printf("일분\n");
			break;
		case 2:
			printf("이분\n");
			break;
		case 3:
			printf("심분\n");
			break;
		case 4:
			printf("사분\n");
			break;
		case 5:
			printf("오분\n");
			break;
		case 6:
			printf("육분\n");
			break;
		case 7:
			printf("칠분\n");
			break;
		case 8:
			printf("팔분\n");
			break;
		case 9:
			printf("구분\n");
			break;

	}
}






int main(){
	

	int Hour = 8;
	int Minute = 2;



	FilterHour(Hour);
	FilterMin(Minute);



	return 0;
}
