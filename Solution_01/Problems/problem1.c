#include<stdio.h>

void problem03_01() {			
	
	printf("���̸� �Է��ϼ���. : ");
	int age;

	// �̷��� scanf������ �Էµ� "Input: 3" �̷������� �ۼ��ؾ� ��
	// �����̽��� �����ؾ� �� !! 
	//scanf_s("Input: %d", &age);

	scanf_s("  %d", &age);
	
	getchar();

	printf("�̸��� �Է��ϼ���. : ");
	char name[12];
	gets_s(name, sizeof(name));

	
	printf("����� ���̴� %d���̰� �̸��� '%s'�Դϴ�.\n", age, name);

	char ch = 0 ;

	printf(" char�ѹ��ڸ� �Է��ϼ��� : ");

	// %c�� ��� , scanf_s()�Լ������� �ּҺ���, ����Ʈũ������� ���ڷ� �Ѱ��־�� �Ѵ�.
	scanf_s("%c", &ch , sizeof(ch));
	printf(" �Է��� ���ڴ� %c �Դϴ�. \n",ch);

}


int main(void) {

	printf("### problem ###");
	
	problem03_01();

}
