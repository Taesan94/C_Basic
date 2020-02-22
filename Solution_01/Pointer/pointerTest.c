#include<stdio.h>
// malloc(), calloc()�Լ��� ���� ��� ����
#include<stdlib.h>
//memset()�Լ��� ���� ��� ����
#include<string.h>
#include<time.h>

void pointerOper() {

	char szBuffer[16] = { "Hello" };

	char *pszData = szBuffer;

	printf("%s", pszData + 1);

}

void ptrmalloc01() {

	int *pList = NULL, i = 0;
	
	// 12����Ʈ �޸𸮸� ������ �Ҵ��ϰ� ���� �ּҸ� pList������ ������ ����

	// (int*)�� ���� ����ȯ�� ������ malloc�� ��ȯ���� void* �̱� �����̴�.
	// c������ ���ص� ������, c++������ �ſ� �����ϰ� �� ������ �����ϴϱ� ��������.
	// �׸��� void* ���� void�� ���̵� �ؼ������ ���ٴ� �ǹ��̴�.
	// ��, ������ �������� ���� ������, �� �ּҰ� ����Ű�� ��� �޸𸮸� � ����(�ڷ���)���� �ؼ������� ���� �������� �ʾ����� �ǹ��Ѵ�.
	pList = (int*)malloc(sizeof(int) * 3);

	// ���� �Ҵ��� ��� �޸𸮸� �迭 �����ڷ� �����Ѵ�.
	pList[0] = 10;
	*(pList + 1) = 20;
	pList[2] = 30;

	for (int i = 0; i < 3; i++) {
		printf("%d\n", pList[i]);
	}
	// �̰� �ּ��ص� ����� �޶����� ������, �ſ� �ɰ��� �����̴� !! �Ҵ�޾����� ��ȯ���� ���� �޸𸮴� ����� �� ���� ������ !
	// ��ó�� �������� �Ǽ��� �޸𸮰� ����� �� ���� ���°� �Ǵ� ���� '�޸� ����(memory leak)'�̶�� �θ��ϴ�.
	free(pList);
}

void badMemoryAccess() {
	char* pszBuffer = NULL;

	pszBuffer = (char*)malloc(12);

	gets(pszBuffer);
	puts(pszBuffer);

	// ����Ȯ���� ���� �ǵ������� �������� ����
	// �ּ��ϸ� ������ �ȳ�����, �ּ�Ǯ�� ������ !
	// free(pszBuffer);
}

void manyArr() {

	char astrList[2][12] = { "hello" , "world" };
	
	//char** pstrList = astrList; // �ȵǳ��̰�..
	char(*pstrList)[12] = astrList;

	puts(pstrList[0]);
	puts(pstrList[1]);

}

int staticTest() {
	// static������ ���Ǵ� �Լ��� ������ ȣ��ǵ� �� �ѹ��� ����ȴ�.
	static int nData = 10;

	++nData;

	// static������ �� ���� return�Ǵ��� ���� �����ϰ��ִ´�.
	return nData;
}

int GetLength(char* c) {
	int length = 0;

	while ( *(c + length) != '\0') {
		 // (c + length)���ϸ� �ּҰ� ������..
		printf("���ڴ� ? : %c \n", *(c + length) );
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
	printf("��� : %s\n", result);
}

void problem_5_p438() {

	char input[100] = { 0 };

	scanf_s("%s", input ,sizeof(input));
	int len1 = strlen(input);

	// ������ ��ĥ���� ������ �ʿ���������� �; ���ڿ� ���̸�ŭ�� malloc(len1)�ߴ���, ����ϴٰ� ������.. 
	// ���⼭�� ������ ����������Ѵ�.
	char* szpBuffer = (char*)malloc(len1+1);
	strcpy_s(szpBuffer, _msize(szpBuffer), input);
	puts(szpBuffer);

	printf(" msize : %d , sizeof : %d ", _msize(szpBuffer), sizeof(szpBuffer));

	// �ι�° �Է�
	scanf_s("%s", input, sizeof(input));
	int len2 = strlen(input);

	// ���ڿ��� ������ ������ �����.
	char* szpResult = (char*)realloc( szpBuffer , len1 + len2 + 1);

	if (szpResult == NULL) {
		free(szpBuffer);
		return;
	}
	
	
	// printf(" msize : %d , sizeof : %d ", _msize(szpResult), sizeof(szpResult));
	// ó���� 2��° ���ڸ� sizeof�� �ߴ��� �ȉ��..
	// char* Ÿ���� �⺻ 4Byte�ΰ�����... ��� 4��������.. �� �³�.. 32��Ʈ�� �ּҰ� �����ȴٰ������ϱ�..
	strcat_s(szpResult, _msize(szpResult), input);
	
	puts(szpResult);

	// �����Ҵ��� �޸� ���� 
	free(szpResult);

	// �� ..���ڵ带 realloc ���Ŀ� �����ؼ� ��� ���������µ�.. �̰� realloc�� ���� �޸𸮸� �Ҵ��ϸ�, szpBuffer�� �ڵ����� free�Ǽ��׷��� �Ф� .. �����ߴ�..
	// printf(" szpBuffer address : [ %p ] , size : %d \n: ", szpBuffer, _msize(szpBuffer));
}

void charPointerArr() {

	char* astrList[3] = { "abc" , "def" , "ghi" };
	
	char astrList2[3] = { "rty" };
	
	
	char* *psz;
	// psz�� char* �̸� ������.
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
	printf("��� ���ڿ��� �Է��Ͻ� �̴ϱ� ? : ");
	scanf_s("%d", &cnt);
	
	char* *pszArr;

	// �ּҰ��� �������ִ� ������, *pszArr���� �� 3���� (char**)Ÿ�� ������ �Ҵ����ش�.
	pszArr = (char**)malloc(sizeof(char*)*cnt);

	int maxLength= 0;
	printf("���ڿ��� �ִ� ũ��� ? : ");
	scanf_s("%d", &maxLength);

	// cnt��ŭ �Է¹����鼭 pszArr�� ��ҿ� �ϳ��� �־��ش�.
	for (int i = 0; i < cnt; i++) {

		char* pszTempArr;
		pszTempArr = (char*)malloc(sizeof(char)*maxLength);

		printf("%d ��° ���� ���� �Է����ּ��� : ", i );
		scanf_s("%s", pszTempArr , _msize(pszTempArr));
		
		pszArr[i] = pszTempArr;

		// free�ϸ� for�� �ۿ��� ���� ����� ��¾ȵ�..
		// free(pszTempArr);
		
		//0x00FC5868 > a 
		//0x00FCA5C0 > b
	}
	// ���
	for (int i = 0; i < cnt; i++) {
		printf("%d ��° ���� ���� : [ %p ] %s \n", i, pszArr[i] , pszArr[i] );
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

	// �齽������ ǥ���ϰ������ \\�� ���.
	char szPath[128] = { "C:\\Program Files\\" };
	
	// _msize�Լ��� heap������ ũ�⸦ �����ϴ°ű��� ��..��.... 
	
	// ������ �̷��� ���µ�..
	// ���⼭ szPath�Լ��� ���Ե� ���ڿ� �ڿ� 3��° ���ڰ� KTS\\�� ���̱����ؼ� ���������� strlen�Լ��� ���ȴ�.
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

// ���ڿ��� ���δ�.
char* mystrcat(char* pszDst, char* pszSrc) {

	// 1. dst ���ڿ��� ���̸� ���Ѵ�.
	while (*pszDst != '\0') {
		printf(" dst�� ���ڿ��� ���̸� ���ϴ� for�� ! \n");
		pszDst++;
	}
		

	// src�� ���� pszDst�ڿ� �ٿ��ش�.
	while(*pszSrc != '\0')
		*pszDst++ = *pszSrc++;

	// ������ null���ڸ� �ٿ��ش�.
	*++pszDst = '\0';

	// -- �����ָ� \0�� ���̶�, puts�� �ϸ� ���� ' ' ���� ���ڿ��� �����.. ! ����� �� !
	return --pszDst;

}

// ���� �������� ������ �˾Ƶθ� �����ϴ�.
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

	// �˻� ��� ���ڿ��� �Է¹޴´�.
	printf(" Input string : ");
	gets_s(szBuffer, sizeof(szBuffer));

	// ã�� '���ڵ�'�� �Է¹޴´�.
	printf("Input charcater set : ");
	gets_s(szSet, sizeof(szSet));

	// ��� ���ڿ��� ��ġ�ϴ� ���ڰ� �ִ��� �˻��Ѵ�.
	while((pszStart = strpbrk(pszStart, szSet)) != NULL) {
		printf("[%p] Index : %d, %c\n", pszStart, pszStart - szBuffer, *pszStart);
		// ��ġ�ϴ� �ϳ��� ã�����Ƿ� �������� �̵��ϰ� ��� ã�´�.
		pszStart++;
	}
}

void useAtoi() {

	char szBuffer[32];
	int nReslut = 0;

	printf("Input String : ");
	gets_s(szBuffer ,sizeof(szBuffer));

	// ���ڿ��� �Է��ϸ� intŸ������ ��ȯ���� ��������.
	nReslut = atoi(szBuffer);
	printf("%d\n", nReslut);

}

void useRand() {

	int i = 0;

	// �̰� �ּ�ó���ϸ� ��� ���� ������ �߻���...
	srand( (unsigned)time( NULL ));

	for (i = 0; i < 10; i++) {
		//printf("%6d\n", rand());
	}
	// 0~10�̸� �����߻�
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


	// findStr�� ù��° ���ڸ� ã�� ���ĺ��� �����ؼ� findStr�� ��� �ִ��� Ȯ���Ѵ�.
	char startC = *findStr + 0; // find[0]

	int maxLen = strlen(findStr);
	int cnt = 0;

	int reslutIndex = -1;
	

	for (int i = 0; i < strlen(destStr); i++) {
		
		// ���������� cnt�Ѵ�.
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

	// ��� ��������.. �Ӽ� > C/C++ > ��ó���� > ��ó���� ���ǿ� [  ;_CRT_SECURE_NO_WARNINGS  ]�߰� ��.
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
	// printf("���� : %d", length);

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
	//printf(" ���ڿ��� ������ġ�� [ %d ] ", index);

	//int arr[5][4] = {
	//{ 10,10,10,10 },
	//{ 10,10,10,10 },
	//{ 10,10,10,10 },
	//{ 10,10,10,10 },
	//{ 1,1,1,1 }
	//};

	//int sum = GetTotal(arr);
	//printf(" �� ���� : %d", sum);

	timeFunc();


	//  Ctrl + K + C �ּ�ó�� ��

}

int main_origin(int argc, char* argv[]) {
	int i = 0;

	for (i = 0; i < argc; i++)
		puts(argv[i]);

	puts("END");
	
	return 0;

}