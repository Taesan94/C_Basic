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


int main(void) {

	printf("### problem ### \n");

	// problem03_01();
	// problem04_01();
	// problem04_02();
	// basic();
	bitOperationTest();
}	
