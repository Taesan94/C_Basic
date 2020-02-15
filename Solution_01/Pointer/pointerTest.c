#include<stdio.h>
// malloc(), calloc()�Լ��� ���� ��� ����
#include<stdlib.h>
//memset()�Լ��� ���� ��� ����
#include<string.h>

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
	// char* Ÿ���� �⺻ 4Byte�ΰ�����... ��� 4��������..
	strcat_s(szpResult, _msize(szpResult), input);
	
	puts(szpResult);

	// �����Ҵ��� �޸� ���� 
	free(szpResult);

	// �� ..���ڵ带 realloc ���Ŀ� �����ؼ� ��� ���������µ�.. �̰� realloc�� ���� �޸𸮸� �Ҵ��ϸ�, szpBuffer�� �ڵ����� free�Ǽ��׷��� �Ф� .. �����ߴ�..
	// printf(" szpBuffer address : [ %p ] , size : %d \n: ", szpBuffer, _msize(szpBuffer));
}

void problem_6_p438() {

	int count;

	printf(" �Է¹��� ���ڿ��� ������ ������ �ּ���. ");
	scanf_s("%d", &count);
	putchar('\n');

	int maxSize;

	printf(" ���ڿ��� �ִ� ũ�⸦ �Է��� �ּ���. ");
	scanf_s("%d", &maxSize);
	putchar('\n');

	// char*Ÿ���� �ּҸ� ����ִ� ���� *words
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
	// printf("���� : %d", length);

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