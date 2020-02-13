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

// ����ũ�����̶�
void maskOper() {
	int nData = 0x11223344;

	printf("%08X\n", nData & 0xFFFF0000 );
	printf("%08X\n", nData & 0x00FFFF00);
	printf("%08X\n", nData & 0x0000FFFF);
	printf("%08X\n", nData & 0xFF0000FF);

	// 11220000
	// 00223300
	// 00003344
	// 11000044
}

void oprelinetfloat01() {
	printf("%d\n", 300 == 299.99999F);
	printf("%d\n", 300 == 299.99999);

	printf("%d\n", 300 == 299.9999F);
	printf("%d\n", 300 == 300.00001F);
}

void threeHangOper() {
	
	int nInput = 0, nSelect = 0;
	scanf_s("%d", &nInput);

	// " '=': ���� �ǿ����ڴ� l-value�̾�� �մϴ�. " �ϸ鼭 ������ !!
	// nInput <= 10 ? nSelect = 10 : nSelect = 20;
		
	// nInput <= 10 ? (nSelect = 10) : (nSelect = 20);
	// nInput <= 10 ? nSelect = 10 : nSelect;

	printf("%d\n", nSelect);
}

void select() {
	int tall;

	printf(" Ű�� �Է��� �ּ��� : ");
	scanf_s("%d", &tall);

	printf(" ��� : %s", tall >= 150 ? "�հ�" : "���հ�");
}

void tournoment() {


	int nMax = 0;
	int a, b, c;
	
	scanf_s("%d,%d,%d", &a, &b, &c);

	nMax = a > b ? a : b;
	nMax = nMax > c ? nMax: c;

	printf("MAX : %d\n", nMax);

}

void problem06_02() {

	int age;

	printf(" ���̸� �Է��� �ּ��� : ");
	scanf_s("%d", &age);

	int won = 1000;

	if (age < 20) won *= (0.75);

	printf("������� : %d", won);
}

void cautionIfScope() {

	int nInput = 0;

	scanf_s("%d", &nInput);

	if (nInput > 10) {
		int nInput = 20;
		printf("%d\n", nInput);

		if (nInput < 20) {
			int nInput = 30;
			printf("%d\n", nInput);
		}
	}

	printf("%d\n" , nInput);
}

void functionFor() {

	int i = 0;

	for (i = 0; i < 5; ++i) {
		printf("%dth\n", i); // th�׳� ���ڳ� ��..��
	}

	i = 0;

	for (; i < 5; i++) {
		printf("[%d] �ʱ� ȭ i ���� ������ ! �ʱ갪 0���� �ڳ�.\n", i );
	}


	for (i = 0; i < 5;) {
		printf("[%d] ����� �����ϸ�.. ���ѷ��� ������ ��..�� �ڵ� 1���� �ȵǴ±� ! !\n",i);
		break;
	}

	for (;; ) {
		printf(" �� . ��. �� . �� . !! ");
		break;
	}

}

void forP1() {

	int i = 1;
	int sum = 0;

	while (i <= 10) {
		sum += i;
		i++;
	}

	printf(" 1~10������ �� : %d ", sum);

}

void forP2() {

	int i = 0;

	scanf_s("%d", &i);
	

	int start = 1;

	while (1) {

		if (i < 2 || i > 9) {
			printf("ERROR");
			break;
		}

		printf("%d & %d = %d\n", i, start, i * start);
		if (start == 9) break;
		start++;
	}

}

void makeT() {

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j <= i; j++) {
			printf("* ");
		}
		printf("\n");
	}
}

void makeT2() {	

	for (int i = 0; i < 5; i++) {

		for (int j = i; j < 4; j++) {
			printf("\t");
		}

		for (int k = 0; k <= i; k++) {
			printf("*\t");
		}

		printf("\n");
	}
	

}

void makeT3() {	

	int index = 0;

	for (int i = 1; i <= 5; i++) {

		for (int j = i; j < 5; j++) {
			printf("\t");
		}

		//1,3,5,7,9
		for (int k = 0; k < (2*i)-1; k++) {
			printf("*\t");
		}

		printf("\n");
	}			
}

void make3_2() {

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5+i; j++) {

			if ( j+i <= 3 ) printf("\t");
			else printf("*\t");
		}
		printf("\n");
	}
}

void loopPractice1() {

	int cnt = 0;
	int sum = 0;

	for (int i = 1; i < 101; i++) {
		if (i % 4 == 0) {
			cnt++;
			sum += i;
	}
		}

	printf(" 4�� ����� �� %d �� �̰�, ������ %d �Դϴ�.", cnt , sum);

}

void loopPractice2() {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i + j <= 3) printf("\t");
			else printf("\t*\t");
		}
		printf("\n");
	}
}

void loopPractice4() {

	int nInput;

	INPUT : 
		printf("Input number : ");
		scanf_s("%d", &nInput);

	if (nInput < 0 || nInput > 10) {
		goto INPUT;
	}

	puts("End");

}

void loopPractice4_answer() {

	int input = 11;

	while (1) {

		if (input < 0 || input > 10) {
			printf("Input number : ");
			scanf_s("%d", &input);
		}
		else break;
	}

}


int main(void) {

	printf("### problem ### \n");

	// problem03_01();
	// problem04_01();
	// problem04_02();
	// basic();
	// bitOperationTest();
	// maskOper();
	// oprelinetfloat01();
	// threeHangOper();
	// select();
	// tournoment();
	// problem06_02();
	// cautionIfScope();
	// functionFor();
	// forP1();
	// forP2();
	// makeT();
	// makeT2();
	// makeT3();
	// make3_2();
	// loopPractice1();
	// loopPractice2();
	// loopPractice3();
	loopPractice4_answer();

}	
