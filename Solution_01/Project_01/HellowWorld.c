#include<stdio.h>

int main(void) {

	printf("############# 시작, Hellow World 출력하기 ############# \n");
	printf("Hellow World\n");
	printf("\n");

	
	// float연산의 위험성
	printf("############# Float연산의 위험성 ############# \n: 오차범위가 크기때문에(128단위) 명백한 오차가 발생 함, 실수 자료형은 double사용 권장 \n");
	// - 연산결과가 똑같이 보임.
	printf("2147483648.0F      : %f\n", 2147483648.0F);
	printf("2147483648.0F - 20 : %f\n", 2147483648.0F - 20 );
	printf("2147483648.0F - 40 : %f\n", 2147483648.0F - 40 );
	printf("2147483648.0F - 60 : %f\n", 2147483648.0F - 60) ;
	printf("2147483648.0F - 64 : %f\n", 2147483648.0F - 64) ;
	printf("2147483648.0F - 65 : %f\n", 2147483648.0F - 65);
	printf("\n");
	printf("############# 문자열은 문자배열. 두 표현은 같다. ############# \n") ;

	char szBuffer[12] = { 'H' , 'e' , 'l' };
	char szBuffer2[12] = { "Hel" };

	printf("szBuffer : ");
	puts(szBuffer);
	printf("szBuffer2 : ");
	puts(szBuffer2);

	printf("\n");
	printf("############# getChar, putChar 사용해보기 ############# \n");
	
	printf(" getChar는 입력 함수 : " );

	// getChar는 Buffer에 데이터가 있다면 하나를 가져온다.
	// Buffer에 데이터가 없다면 입력받고, 바로 하나를 가져온다.	    
	char input = getchar();

	printf(" putChar는 출력 함수 ! \n");

	int seq = 1;

	while (input != '\n') {
		printf("%d 번째 input 값 : ",seq);
		putchar(input);
		printf("\n");
		seq++;
		input = getchar();
	}

	return 0;
}