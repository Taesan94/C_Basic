#include<stdio.h>
// malloc(), calloc()함수를 위한 헤더 포함
#include<stdlib.h>
//memset()함수를 위한 헤더 포함
#include<string.h>
#include<time.h>

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
	// char* 타입은 기본 4Byte인가보다... 계속 4만찍힌다.. 아 맞네.. 32비트로 주소가 구성된다고했으니깐..
	strcat_s(szpResult, _msize(szpResult), input);
	
	puts(szpResult);

	// 동적할당한 메모리 해제 
	free(szpResult);

	// 아 ..이코드를 realloc 이후에 수행해서 계속 에러가났는데.. 이거 realloc가 새로 메모리를 할당하면, szpBuffer가 자동으로 free되서그렇네 ㅠㅠ .. 뻘짓했다..
	// printf(" szpBuffer address : [ %p ] , size : %d \n: ", szpBuffer, _msize(szpBuffer));
}

void charPointerArr() {

	char* astrList[3] = { "abc" , "def" , "ghi" };
	
	char astrList2[3] = { "rty" };
	
	
	char* *psz;
	// psz가 char* 이면 에러남.
	psz = astrList;
	
	char *psz2;
	psz2 = astrList2;

	printf("astrList2 : %c\n", psz2[0]);
	printf("astrList2 : %c\n", psz2[1]);
	printf("astrList2 : %c\n", psz2[2]);

	printf("astrList : %s\n", psz[0]);
	printf("astrList : %s\n", psz[1]);
	printf("astrList : %s\n", psz[2]);

}

void problem_6_p438() {
	
	int cnt = 0;
	printf("몇개의 문자열을 입력하실 겁니까 ? : ");
	scanf_s("%d", &cnt);
	
	char* *pszArr;

	// 주소값을 가지고있는 포인터, *pszArr에는 총 3개의 (char**)타입 공간을 할당해준다.
	pszArr = (char**)malloc(sizeof(char*)*cnt);

	int maxLength= 0;
	printf("문자열의 최대 크기는 ? : ");
	scanf_s("%d", &maxLength);

	// cnt만큼 입력받으면서 pszArr의 요소에 하나씩 넣어준다.
	for (int i = 0; i < cnt; i++) {

		char* pszTempArr;
		pszTempArr = (char*)malloc(sizeof(char)*maxLength);

		printf("%d 번째 문자 열을 입력해주세요 : ", i );
		scanf_s("%s", pszTempArr , _msize(pszTempArr));
		
		pszArr[i] = pszTempArr;

		// free하면 for문 밖에서 값이 제대로 출력안됨..
		// free(pszTempArr);
		
		//0x00FC5868 > a 
		//0x00FCA5C0 > b
	}
	// 출력
	for (int i = 0; i < cnt; i++) {
		printf("%d 번째 문자 열은 : [ %p ] %s \n", i, pszArr[i] , pszArr[i] );
		free(pszArr[i]);
	}

	free(pszArr);
}

int* badFunction() {
	int nData = 10;
	return &nData;
}

void test() {
	int aList[3] = { 10, 20, 30 };

	int* pnData = aList;

	// pnData + 1 = 100;
	*(pnData + 1) = 100;
}

void originStrcat() {

	// 백슬래쉬를 표현하고싶을때 \\로 기술.
	char szPath[128] = { "C:\\Program Files\\" };
	
	// _msize함수는 heap영역의 크기를 측정하는거구나 ㅡ..ㅡ.... 
	
	// 원래는 이렇게 쓰는데..
	// 여기서 szPath함수에 포함된 문자열 뒤에 3번째 인자값 KTS\\를 붙이기위해서 내부적으로 strlen함수가 사용된다.
	strcat_s(szPath, sizeof(szPath), "KTS\\");
	strcat_s(szPath, sizeof(szPath), "C_programming");

	puts(szPath);

}

char* pointerCheck(char* pszDst, char* pszSrc) {

	//0x0043FBE8

	// pszDst  >> 0x0043FBE8 >> abcd
	// *pszDst >> 
	// &pszDst >> 0x0043FAF4 >> e8 fb 43 00 cc fb 43 00

	printf(" pszDst : [ %p , %s ] \n", pszDst, pszDst);
	printf(" *pszDst : [ %p , %c ] \n ", *pszDst+0 , *pszDst );

}

// 문자열을 붙인다.
char* mystrcat(char* pszDst, char* pszSrc) {

	// 1. dst 문자열의 길이를 구한다.
	while (*pszDst != '\0') {
		printf(" dst의 문자열의 길이를 구하는 for문 ! \n");
		pszDst++;
	}
		

	// src의 값을 pszDst뒤에 붙여준다.
	while(*pszSrc != '\0')
		*pszDst++ = *pszSrc++;

	// 마지막 null문자를 붙여준다.
	*++pszDst = '\0';

	// -- 안해주면 \0이 끝이라서, puts로 하면 최초 ' ' 앞의 문자열만 출력함.. ! 해줘야 됨 !
	return --pszDst;

}

// 자주 쓰이지는 않지만 알아두면 유용하다.
void usersprintf() {

	char szPath[128] = { 0 };
	char szBuffer[128] = { 0 };

	printf(" Input path : ");
	gets_s(szBuffer , sizeof(szBuffer));

	sprintf_s(szPath, sizeof(szPath), "c:\\Program Files\\%s", szBuffer);
	
	puts(szPath);

}

void useStrbrk() {

	char szBuffer[128] = { 0 };
	char szSet[128] = { 0 };
	
	char *pszStart = szBuffer;

	// 검색 대상 문자열을 입력받는다.
	printf(" Input string : ");
	gets_s(szBuffer, sizeof(szBuffer));

	// 찾을 '문자들'을 입력받는다.
	printf("Input charcater set : ");
	gets_s(szSet, sizeof(szSet));

	// 대상 문자열에 일치하는 문자가 있는지 검색한다.
	while((pszStart = strpbrk(pszStart, szSet)) != NULL) {
		printf("[%p] Index : %d, %c\n", pszStart, pszStart - szBuffer, *pszStart);
		// 일치하는 하나를 찾았으므로 다음으로 이동하고 계속 찾는다.
		pszStart++;
	}
}

void useAtoi() {

	char szBuffer[32];
	int nReslut = 0;

	printf("Input String : ");
	gets_s(szBuffer ,sizeof(szBuffer));

	// 문자열을 입력하면 int타입으로 반환함을 주의하자.
	nReslut = atoi(szBuffer);
	printf("%d\n", nReslut);

}

void useRand() {

	int i = 0;

	// 이거 주석처리하면 계속 같은 난수가 발생함...
	srand( (unsigned)time( NULL ));

	for (i = 0; i < 10; i++) {
		//printf("%6d\n", rand());
	}
	// 0~10미만 난수발생
	for (i = 0; i < 10; i++) {
		printf("%6d\n", rand() % 3);
	}
}

void useSystem() {
	char szCommand[512] = { 0 };
	printf("Input command : ");
	gets_s(szCommand,sizeof(szCommand));

	system(szCommand);
}

int problem_chapter12_01(char* destStr, char* findStr) {


	// findStr의 첫번째 글자를 찾은 이후부터 연속해서 findStr가 모두 있는지 확인한다.
	char startC = *findStr + 0; // find[0]

	int maxLen = strlen(findStr);
	int cnt = 0;

	int reslutIndex = -1;
	

	for (int i = 0; i < strlen(destStr); i++) {
		
		// 시작점부터 cnt한다.
		if (destStr[i] == startC) {		
			reslutIndex = i;
			if (maxLen == 1) return reslutIndex;
			while (cnt < maxLen-1 && i <= sizeof(destStr)) {
				if (findStr[++cnt] != destStr[++i]) {
					return -1;
				}
			}
			break;
		}
	}
	return reslutIndex;
}

int GetTotal(int (*arr)[4]) {

	int sum = 0;

	for (int i = 0; i < 20; i++) {
		sum += arr[0][i];
	}

	return sum;
}

void timeFunc() {

	struct tm* ptime = { 0 };
	time_t t = 0;

	t = time(NULL);
	ptime = localtime(&t);

	// 계속 에러나서.. 속성 > C/C++ > 전처리기 > 전처리기 정의에 [  ;_CRT_SECURE_NO_WARNINGS  ]추가 함.
	printf("%d\n", t);
	printf("%s", ctime(&t));

	printf("%04d-%02d-%02d\n", ptime->tm_year + 1900, ptime->tm_mon + 1, ptime->tm_mday);



}

void main() {

	printf("### Pointer ###\n");

	// pointerOper();
	// ptrmalloc01();
	// badMemoryAccess();
	// manyArr();

	// printf("%d\n" , staticTest());
	// printf("%d\  n", staticTest());
	// printf("%d\n", staticTest());

	// char arr[15] = { "helloworld" };
	// int length = GetLength(arr);
	// printf("길이 : %d", length);

	//char arr[10] ;
	//scanf_s("%s", arr , sizeof(arr));
	//myStrrev(arr);

	// problem_5_p438();

	// problem_6_p438();
	
	// int* pnReslut = NULL;
	// pnReslut = badFunction();
	// printf("%d\n" , *pnReslut);

	// test();

	// originStrcat();

	// pointerCheck(dest, src);

	//char dest[20] = { 0 };
	//char* pszEnd = NULL;

	// pszEnd = mystrcat(dest, "abcd");
	// pszEnd = mystrcat(pszEnd, "aaa");
	// pszEnd = mystrcat(pszEnd, "bbb");
	// pszEnd = mystrcat(pszEnd, "ccc");
	// puts(dest);

	// usersprintf();

	// useStrbrk();
	// useAtoi();
	userRand();

	// useRand();

	// useSystem();

	//char destStr[] = {"aaabcdaaa"};
	//char findStr[] = {"bcd"};
	//int index = problem_chapter12_01(destStr, findStr);
	//printf(" 문자열의 시작위치는 [ %d ] ", index);

	//int arr[5][4] = {
	//{ 10,10,10,10 },
	//{ 10,10,10,10 },
	//{ 10,10,10,10 },
	//{ 10,10,10,10 },
	//{ 1,1,1,1 }
	//};

	//int sum = GetTotal(arr);
	//printf(" 총 합은 : %d", sum);

	timeFunc();


	//  Ctrl + K + C 주석처리 ㅎ

}

int main_origin(int argc, char* argv[]) {
	int i = 0;

	for (i = 0; i < argc; i++)
		puts(argv[i]);

	puts("END");
	
	return 0;

}