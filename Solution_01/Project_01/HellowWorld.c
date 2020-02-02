#include<stdio.h>

// float자료형의 위험성
void warningFloat() {

	printf("############# Float연산의 위험성 ############# \n: 오차범위가 크기때문에(128단위) 명백한 오차가 발생 함, 실수 자료형은 double사용 권장 \n");
	// - 연산결과가 똑같이 보임.
	printf("2147483648.0F      : %f\n", 2147483648.0F);
	printf("2147483648.0F - 20 : %f\n", 2147483648.0F - 20);
	printf("2147483648.0F - 40 : %f\n", 2147483648.0F - 40);
	printf("2147483648.0F - 60 : %f\n", 2147483648.0F - 60);
	printf("2147483648.0F - 64 : %f\n", 2147483648.0F - 64);
	printf("2147483648.0F - 65 : %f\n", 2147483648.0F - 65);
	printf("\n");
	printf("############# 문자열은 문자배열. 두 표현은 같다. ############# \n");

	char szBuffer[12] = { 'H' , 'e' , 'l' };
	char szBuffer2[12] = { "Hel" };

	printf("szBuffer : ");
	puts(szBuffer);
	printf("szBuffer2 : ");
	puts(szBuffer2);
}

// getCharPutChar 사용해보기
void getCharPutChar() {

	printf("\n");
	printf("############# getChar, putChar 사용해보기 ############# \n");

	printf(" getChar는 입력 함수 : ");

	// getChar는 Buffer에 데이터가 있다면 하나를 가져온다.
	// Buffer에 데이터가 없다면 입력받고, 바로 하나를 가져온다.
	char input = getchar();

	printf(" putChar는 출력 함수 ! \n");

	int seq = 1;

	while (input != '\n') {
		printf("%d 번째 input 값 : ", seq);
		putchar(input);
		printf("\n");
		seq++;
		input = getchar();
	}
}


// gets, puts , scanf 사용해보기
void getsPutsScanf() {
	printf("\n");
	printf("############# gets, puts , scanf_s 사용해보기 ############# \n");	
	char words[10];	

	printf(" char배열 words의 크기는 %d 입니다.\n", sizeof(words));

	printf(" gets_s 함수로 입력 받기 : ");
	gets_s(words, sizeof(words));
	printf(" puts 함수로 출력하기 : ");
	puts(words);

	int nData = 0;
	printf(" scanf_s로 정수 입력받기 :  ");
	scanf_s("%d", &nData); 
	printf(" nData : %d\n", nData);

	char nChars[10] ;
	printf(" scanf_s로 char[] 입력받기 :  ");

	//인자값에 size도 같이 적어줌.
	scanf_s("%s", nChars , 10); 
	printf(" nChars : %s\n", nChars);

	// 개행문자 처리해주기위함. 
	// 이건 window에서만 먹힘 .. 
	// 리눅스는 _fpurge(stdin)..
	// visualStudio 2015부터 안먹힌다고함.
	// %c입력받을때 앞에 %*c사용하면 버퍼를 받지만 버리고, 다음 %c를 통해 데이터를 받는다.
	// "%c"를 한칸 space해서 " %c" 이런식으로하면 \n을 whit space로 인식하고 넘긴다.
	fflush(stdin);
	//getchar(); // 이렇게 \n을 빼내도 되긴하는데.. 좋은방법은아니다.

	char nChar;
	printf(" scanf_s로 char 한 글자 입력받기 :  ");
	//인자값에 size도 같이 적어줌.
	//scanf_s("%*c%c", &nChar, 1);

	scanf_s(" %c", &nChar, 1);
	printf(" nChar : %c\n", nChar);

}

int main(void) {

	printf("############# 시작, Hellow World 출력하기 ############# \n");
	printf("Hellow World\n");
	printf("\n");
	
	//1
	//warningFloat();
	//2
	//getCharPutChar();
	//3
	getsPutsScanf();

	return 0;
}
