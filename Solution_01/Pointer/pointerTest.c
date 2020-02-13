#include<stdio.h>
#include<stdlib.h>

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

void main() {
	printf("### Pointer ###\n");

	// pointerOper();

	ptrmalloc01();
}