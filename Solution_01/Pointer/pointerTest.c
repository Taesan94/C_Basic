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

	// 동적 할당한 대상 메모리를 배열 연산자로 접근한다.
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
	// 주석하면 에러가 안나지만, 주석풀면 에러남 !
	// free(pszBuffer);
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

void myStrrev(char *str) {

	int len = sizeof(str);
	int index = 0;

	char result[sizeof(str)] = { 0 };

	for (int i = len-1; i >= 0; i--) {
		if (str[i] != '\0') {
			result[index] = str[i];
			index++;
		}
	}
	printf("결과 : %s\n", result);
}

void problem_5_p438() {

	char input[100] = { 0 };

	scanf_s("%s", input ,sizeof(input));
	int len1 = strlen(input);

	// 어차피 합칠꺼면 공백이 필요없지않을까 싶어서 문자열 길이만큼만 malloc(len1)했더니, 출력하다가 에러남.. 
	// 여기서도 공백을 포함해줘야한다.
	char* szpBuffer = (char*)malloc(len1+1);
	strcpy_s(szpBuffer, _msize(szpBuffer), input);
	puts(szpBuffer);

	printf(" msize : %d , sizeof : %d ", _msize(szpBuffer), sizeof(szpBuffer));

	// 두번째 입력
	scanf_s("%s", input, sizeof(input));
	int len2 = strlen(input);

	// 문자열을 저장할 공간을 만든다.
	char* szpResult = (char*)realloc( szpBuffer , len1 + len2 + 1);

	if (szpResult == NULL) {
		free(szpBuffer);
		return;
	}
	
	
	// printf(" msize : %d , sizeof : %d ", _msize(szpResult), sizeof(szpResult));
	// 처음이 2번째 인자를 sizeof로 했더니 안됬다..
	// char* 타입은 기본 4Byte인가보다... 계속 4만찍힌다..
	strcat_s(szpResult, _msize(szpResult), input);
	
	puts(szpResult);

	// 동적할당한 메모리 해제 
	free(szpResult);

	// 아 ..이코드를 realloc 이후에 수행해서 계속 에러가났는데.. 이거 realloc가 새로 메모리를 할당하면, szpBuffer가 자동으로 free되서그렇네 ㅠㅠ .. 뻘짓했다..
	// printf(" szpBuffer address : [ %p ] , size : %d \n: ", szpBuffer, _msize(szpBuffer));
}

void problem_6_p438() {

	int count;

	printf(" 입력받을 문자열의 갯수를 지정해 주세요. ");
	scanf_s("%d", &count);
	putchar('\n');

	int maxSize;

	printf(" 문자열의 최대 크기를 입력해 주세요. ");
	scanf_s("%d", &maxSize);
	putchar('\n');

	// char*타입의 주소를 담고있는 변수 *words
	char* words;
	words = calloc( maxSize, sizeof(char));

	for (int i = 0; i < count; i++) {
		scanf_s("%s", words + i, maxSize);
	}

	for (int i = 0; i < count; i++) {
		//printf("%s : " , *words[i] );
	}


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

	// char arr[15] = { "helloworld" };
	// int length = GetLength(arr);
	// printf("길이 : %d", length);

	//char arr[10] ;
	//scanf_s("%s", arr , sizeof(arr));
	//myStrrev(arr);

	 problem_5_p438();

	// problem_6_p438();




}

int main_origin(int argc, char* argv[]) {
	int i = 0;

	for (i = 0; i < argc; i++)
		puts(argv[i]);

	puts("END");
	
	return 0;

}