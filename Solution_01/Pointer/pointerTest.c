#include<stdio.h>
// malloc(), calloc()함수를 위한 헤더 포함
#include<stdlib.h>
//memset()함수를 위한 헤더 포함
#include<string.h>

void pointerOper() {

	char szBuffer[16] = { "Hello" };

	char *pszData = szBuffer;

	printf("%s", pszData + 1);

}

void ptrmalloc01() {

	int *pList = NULL, i = 0;
	
	// 12바이트 메모리르 ㄹ동적 할당하고 시작 주소를 pList포인터 변수에 저장

	// (int*)로 강제 형변환한 이유는 malloc의 반환형이 void* 이기 때문이다.
	// c에서는 안해도 되지만, c++에서는 매우 강력하게 이 문제를 지적하니깐 주의하자.
	// 그리고 void* 에서 void는 길이도 해석방법도 없다는 의미이다.
	// 즉, 본질이 포인터인 것은 맞지만, 이 주소가 가리키는 대상 메모리를 어떤 형식(자료형)으로 해석할지는 아직 결정되지 않았음을 의미한다.
	pList = (int*)malloc(sizeof(int) * 3);

	// 동적 할당한 대상 메모리르 배열 연산자로 접근한다.
	pList[0] = 10;
	*(pList + 1) = 20;
	pList[2] = 30;

	for (int i = 0; i < 3; i++) {
		printf("%d\n", pList[i]);
	}
	// 이거 주석해도 결과는 달라지지 않지만, 매우 심각한 오류이다 !! 할당받았지만 반환하지 않은 메모리는 사용할 수 없기 때문에 !
	// 이처럼 개발자의 실수로 메모리가 사용할 수 없는 상태가 되는 것을 '메모리 누수(memory leak)'이라고 부릅니다.
	free(pList);
}

void badMemoryAccess() {
	char* pszBuffer = NULL;

	pszBuffer = (char*)malloc(12);

	gets(pszBuffer);
	puts(pszBuffer);

	// 오류확인을 위해 의도적으로 해제하지 않음
	  free(pszBuffer);
}

void manyArr() {

	char astrList[2][12] = { "hello" , "world" };
	
	//char** pstrList = astrList; // 안되네이거..
	char(*pstrList)[12] = astrList;

	puts(pstrList[0]);
	puts(pstrList[1]);

}

int staticTest() {
	// static변수의 정의는 함수가 여러번 호출되도 단 한번만 적용된다.
	static int nData = 10;

	++nData;

	// static변수는 이 값이 return되더라도 값을 유지하고있는다.
	return nData;
}

int GetLength(char* c) {
	int length = 0;

	while ( *(c + length) != '\0') {
		 // (c + length)로하면 주소값 찍히네..
		printf("문자는 ? : %c \n", *(c + length) );
		length++;
	}
	return length;
}


void main() {
	printf("### Pointer ###\n");

	// pointerOper();
	// ptrmalloc01();
	// badMemoryAccess();
	// manyArr();

	// printf("%d\n" , staticTest());
	// printf("%d\n", staticTest());
	// printf("%d\n", staticTest());

	char arr[15] = { "helloworld" };
	int length = GetLength(arr);

	printf("길이 : %d", length);

}

int main_origin(int argc, char* argv[]) {
	int i = 0;

	for (i = 0; i < argc; i++)
		puts(argv[i]);

	puts("END");
	
	return 0;

}