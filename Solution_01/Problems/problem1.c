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

	char ch = 0 ;

	printf(" char한문자를 입력하세요 : ");

	// %c의 경우 , scanf_s()함수에서는 주소변수, 바이트크기단위를 인자로 넘겨주어야 한다.
	scanf_s("%c", &ch , sizeof(ch));
	printf(" 입력한 문자는 %c 입니다. \n",ch);

}

void practice() {

	getchar();
	putchar(getchar());
}


int main(void) {

	printf("### problem ### \n");
	
	//problem03_01();

	practice();

}
