#include<stdio.h>

void problem03_01() {

	printf("���̸� �Է��ϼ���. : ");
	int age;

	// �̷��� scanf������ �Էµ� "Input: 3" �̷������� �ۼ��ؾ� ��
	// �����̽��� �����ؾ� �� !! 
	//scanf_s("Input: %d", &age);

	// �Է¹��ۿ� \n ó���ϱ����ؼ� %*c�߰� �ߴ�.
	// scanf()�Լ��� ���� ���ڿ��� %��ȣ�� ���� ���� ���̿� ��ġ�� ��ǥ(*)�� '����'�� �ǹ��Ѵ�.
	scanf_s("%d%*c", &age);

	printf("�̸��� �Է��ϼ���. : ");
	char name[12];
	gets_s(name, sizeof(name));


	printf("����� ���̴� %d���̰� �̸��� '%s'�Դϴ�.\n", age, name);

	char ch = 0;

	printf(" char�ѹ��ڸ� �Է��ϼ��� : ");

	// %c�� ��� , scanf_s()�Լ������� �ּҺ���, ����Ʈũ������� ���ڷ� �Ѱ��־�� �Ѵ�.
	scanf_s("%c", &ch, sizeof(ch));
	printf(" �Է��� ���ڴ� %c �Դϴ�. \n", ch);

}

void problem04_01() {
	
	int a, b;
	printf("���� a,b�� �Է��ϼ���. a,b ���·� �Է��ϼ���! \n");
	scanf_s("%d,%d",&a,&b);
	printf("�� ������ ����� %.2f �Դϴ�", (a + b) / 2.0f );

}

void problem04_02() {
	
	int second = 0;
	
	printf("�ʸ� �Է��ϼ���. : ");
	scanf_s("%d", &second);
	
	int input, hour, minute;

	// ó�� �Է� ��
	input = second;
	
	// �ð������� �������� 60 * 60 �̴ϱ� 3600 ��..
	hour = second/3600;

	second %= 3600;
	
	// �д����� 60��.
	minute = second / 60;

	second %= 60;
	
	printf("%d�ʴ� %02d�ð� %02d�� %02d�� �Դϴ�.", input, hour, minute, second);

}

void basic() {

	int nInput, nTotal = 0;

	printf(" ù ��° ���� �Է� : ");
	scanf_s("%d", &nInput);
	nTotal += nInput;
	printf(" �� ��° ���� �Է� : ");
	scanf_s("%d", &nInput);
	nTotal += nInput;
	printf(" �� ��° ���� �Է� : ");
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
