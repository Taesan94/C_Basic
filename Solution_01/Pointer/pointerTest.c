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
	  free(pszBuffer);
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

	printf("���� : %d", length);

}

int main_origin(int argc, char* argv[]) {
	int i = 0;

	for (i = 0; i < argc; i++)
		puts(argv[i]);

	puts("END");
	
	return 0;

}