#include<stdio.h>

void problem03_01() {

	printf("나이를 입력하세요. : ");
	int age;

	// 이렇게 scanf쓰려면 입력도 "Input: 3" 이런식으로 작성해야 함
	// 스페이스도 주의해야 함 !! 
	//scanf_s("Input: %d", &age);

	// 입력버퍼에 \n 처리하기위해서 %*c추가 했다.
	// scanf()함수의 형식 문자에서 %기호와 형식 문자 사이에 위치한 별표(*)는 '버림'을 의미한다.
	scanf_s("%d%*c", &age);

	printf("이름을 입력하세요. : ");
	char name[12];
	gets_s(name, sizeof(name));


	printf("당신의 나이는 %d살이고 이름은 '%s'입니다.\n", age, name);

	char ch = 0;

	printf(" char한문자를 입력하세요 : ");

	// %c의 경우 , scanf_s()함수에서는 주소변수, 바이트크기단위를 인자로 넘겨주어야 한다.
	scanf_s("%c", &ch, sizeof(ch));
	printf(" 입력한 문자는 %c 입니다. \n", ch);

}

void problem04_01() {
	
	int a, b;
	printf("정수 a,b를 입력하세요. a,b 형태로 입력하세요! \n");
	scanf_s("%d,%d",&a,&b);
	printf("두 정수의 평균은 %.2f 입니다", (a + b) / 2.0f );

}

void problem04_02() {
	
	int second = 0;
	
	printf("초를 입력하세요. : ");
	scanf_s("%d", &second);
	
	int input, hour, minute;

	// 처음 입력 초
	input = second;
	
	// 시간단위로 나누려면 60 * 60 이니깐 3600 초..
	hour = second/3600;

	second %= 3600;
	
	// 분단위는 60초.
	minute = second / 60;

	second %= 60;
	
	printf("%d초는 %02d시간 %02d분 %02d초 입니다.", input, hour, minute, second);

}

void basic() {

	int nInput, nTotal = 0;

	printf(" 첫 번째 숫자 입력 : ");
	scanf_s("%d", &nInput);
	nTotal += nInput;
	printf(" 두 번째 숫자 입력 : ");
	scanf_s("%d", &nInput);
	nTotal += nInput;
	printf(" 세 번째 숫자 입력 : ");
	scanf_s("%d", &nInput);
	nTotal += nInput;

	printf("Total : %d\n", nTotal);
}

void bitOperationTest() {

	printf("%08X\n", 0xFFFFFFFF & 0x00080000);
	printf("%08X\n", 0xAAAABBBB & 0x00080000);
	printf("%08X\n", 0xAABBCCDD & 0x00080000);
	
	printf("%08X\n", 0xFFFFFFFF | 0x00080000);
	printf("%08X\n", 0x11223344 | 0x00080000);
	printf("%08X\n", 0x00000000 | 0x000F0000);

}

// 마스크연산이란
void maskOper() {
	int nData = 0x11223344;

	printf("%08X\n", nData & 0xFFFF0000 );
	printf("%08X\n", nData & 0x00FFFF00);
	printf("%08X\n", nData & 0x0000FFFF);
	printf("%08X\n", nData & 0xFF0000FF);

	// 11220000
	// 00223300
	// 00003344
	// 11000044
}

void oprelinetfloat01() {
	printf("%d\n", 300 == 299.99999F);
	printf("%d\n", 300 == 299.99999);

	printf("%d\n", 300 == 299.9999F);
	printf("%d\n", 300 == 300.00001F);
}

void threeHangOper() {
	
	int nInput = 0, nSelect = 0;
	scanf_s("%d", &nInput);

	// " '=': 왼쪽 피연산자는 l-value이어야 합니다. " 하면서 에러남 !!
	// nInput <= 10 ? nSelect = 10 : nSelect = 20;
		
	// nInput <= 10 ? (nSelect = 10) : (nSelect = 20);
	// nInput <= 10 ? nSelect = 10 : nSelect;

	printf("%d\n", nSelect);
}

void select() {
	int tall;

	printf(" 키를 입력해 주세요 : ");
	scanf_s("%d", &tall);

	printf(" 결과 : %s", tall >= 150 ? "합격" : "불합격");
}

void tournoment() {


	int nMax = 0;
	int a, b, c;
	
	scanf_s("%d,%d,%d", &a, &b, &c);

	nMax = a > b ? a : b;
	nMax = nMax > c ? nMax: c;

	printf("MAX : %d\n", nMax);

}

void problem06_02() {

	int age;

	printf(" 나이를 입력해 주세요 : ");
	scanf_s("%d", &age);

	int won = 1000;

	if (age < 20) won *= (0.75);

	printf("최종요금 : %d", won);
}

void cautionIfScope() {

	int nInput = 0;

	scanf_s("%d", &nInput);

	if (nInput > 10) {
		int nInput = 20;
		printf("%d\n", nInput);

		if (nInput < 20) {
			int nInput = 30;
			printf("%d\n", nInput);
		}
	}

	printf("%d\n" , nInput);
}

void functionFor() {

	int i = 0;

	for (i = 0; i < 5; ++i) {
		printf("%dth\n", i); // th그냥 문자네 ㅡ..ㅡ
	}

	i = 0;

	for (; i < 5; i++) {
		printf("[%d] 초기 화 i 생략 가능함 ! 초깃값 0부터 겠네.\n", i );
	}


	for (i = 0; i < 5;) {
		printf("[%d] 계수기 생략하면.. 무한루프 빠지네 ㅡ..ㅡ 자동 1증가 안되는군 ! !\n",i);
		break;
	}

	for (;; ) {
		printf(" 무 . 한. 루 . 프 . !! ");
		break;
	}

}

void forP1() {

	int i = 1;
	int sum = 0;

	while (i <= 10) {
		sum += i;
		i++;
	}

	printf(" 1~10까지의 합 : %d ", sum);

}

void forP2() {

	int i = 0;

	scanf_s("%d", &i);
	

	int start = 1;

	while (1) {

		if (i < 2 || i > 9) {
			printf("ERROR");
			break;
		}

		printf("%d & %d = %d\n", i, start, i * start);
		if (start == 9) break;
		start++;
	}

}

void makeT() {

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j <= i; j++) {
			printf("* ");
		}
		printf("\n");
	}
}

void makeT2() {	

	for (int i = 0; i < 5; i++) {

		for (int j = i; j < 4; j++) {
			printf("\t");
		}

		for (int k = 0; k <= i; k++) {
			printf("*\t");
		}

		printf("\n");
	}
	

}

void makeT3() {	

	int index = 0;

	for (int i = 1; i <= 5; i++) {

		for (int j = i; j < 5; j++) {
			printf("\t");
		}

		//1,3,5,7,9
		for (int k = 0; k < (2*i)-1; k++) {
			printf("*\t");
		}

		printf("\n");
	}			
}

void make3_2() {

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5+i; j++) {

			if ( j+i <= 3 ) printf("\t");
			else printf("*\t");
		}
		printf("\n");
	}
}

void loopPractice1() {

	int cnt = 0;
	int sum = 0;

	for (int i = 1; i < 101; i++) {
		if (i % 4 == 0) {
			cnt++;
			sum += i;
	}
		}

	printf(" 4의 배수는 총 %d 개 이고, 총합은 %d 입니다.", cnt , sum);

}

void loopPractice2() {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i + j <= 3) printf("\t");
			else printf("\t*\t");
		}
		printf("\n");
	}
}

void loopPractice4() {

	int nInput;

	INPUT : 
		printf("Input number : ");
		scanf_s("%d", &nInput);

	if (nInput < 0 || nInput > 10) {
		goto INPUT;
	}

	puts("End");

}

void loopPractice4_answer() {

	int input = 11;

	while (1) {

		if (input < 0 || input > 10) {
			printf("Input number : ");
			scanf_s("%d", &input);
		}
		else break;
	}

}


int main(void) {

	printf("### problem ### \n");

	// problem03_01();
	// problem04_01();
	// problem04_02();
	// basic();
	// bitOperationTest();
	// maskOper();
	// oprelinetfloat01();
	// threeHangOper();
	// select();
	// tournoment();
	// problem06_02();
	// cautionIfScope();
	// functionFor();
	// forP1();
	// forP2();
	// makeT();
	// makeT2();
	// makeT3();
	// make3_2();
	// loopPractice1();
	// loopPractice2();
	// loopPractice3();
	loopPractice4_answer();

}	
