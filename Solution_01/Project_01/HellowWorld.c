#include<stdio.h>

// float�ڷ����� ���輺
void warningFloat() {

	printf("############# Float������ ���輺 ############# \n: ���������� ũ�⶧����(128����) ����� ������ �߻� ��, �Ǽ� �ڷ����� double��� ���� \n");
	// - �������� �Ȱ��� ����.
	printf("2147483648.0F      : %f\n", 2147483648.0F);
	printf("2147483648.0F - 20 : %f\n", 2147483648.0F - 20);
	printf("2147483648.0F - 40 : %f\n", 2147483648.0F - 40);
	printf("2147483648.0F - 60 : %f\n", 2147483648.0F - 60);
	printf("2147483648.0F - 64 : %f\n", 2147483648.0F - 64);
	printf("2147483648.0F - 65 : %f\n", 2147483648.0F - 65);
	printf("\n");
	printf("############# ���ڿ��� ���ڹ迭. �� ǥ���� ����. ############# \n");

	char szBuffer[12] = { 'H' , 'e' , 'l' };
	char szBuffer2[12] = { "Hel" };

	printf("szBuffer : ");
	puts(szBuffer);
	printf("szBuffer2 : ");
	puts(szBuffer2);
}

// getCharPutChar ����غ���
void getCharPutChar() {

	printf("\n");
	printf("############# getChar, putChar ����غ��� ############# \n");

	printf(" getChar�� �Է� �Լ� : ");

	// getChar�� Buffer�� �����Ͱ� �ִٸ� �ϳ��� �����´�.
	// Buffer�� �����Ͱ� ���ٸ� �Է¹ް�, �ٷ� �ϳ��� �����´�.
	char input = getchar();

	printf(" putChar�� ��� �Լ� ! \n");

	int seq = 1;

	while (input != '\n') {
		printf("%d ��° input �� : ", seq);
		putchar(input);
		printf("\n");
		seq++;
		input = getchar();
	}
}


// gets, puts , scanf ����غ���
void getsPutsScanf() {
	printf("\n");
	printf("############# gets, puts , scanf_s ����غ��� ############# \n");	
	char words[10];	

	printf(" char�迭 words�� ũ��� %d �Դϴ�.\n", sizeof(words));

	printf(" gets_s �Լ��� �Է� �ޱ� : ");
	gets_s(words, sizeof(words));
	printf(" puts �Լ��� ����ϱ� : ");
	puts(words);

	int nData = 0;
	printf(" scanf_s�� ���� �Է¹ޱ� :  ");
	scanf_s("%d", &nData); 
	printf(" nData : %d\n", nData);

	char nChars[10] ;
	printf(" scanf_s�� char[] �Է¹ޱ� :  ");

	//���ڰ��� size�� ���� ������.
	scanf_s("%s", nChars , 10); 
	printf(" nChars : %s\n", nChars);

	// ���๮�� ó�����ֱ�����. 
	// �̰� window������ ���� .. 
	// �������� _fpurge(stdin)..
	// visualStudio 2015���� �ȸ����ٰ���.
	// %c�Է¹����� �տ� %*c����ϸ� ���۸� ������ ������, ���� %c�� ���� �����͸� �޴´�.
	// "%c"�� ��ĭ space�ؼ� " %c" �̷��������ϸ� \n�� whit space�� �ν��ϰ� �ѱ��.
	fflush(stdin);
	//getchar(); // �̷��� \n�� ������ �Ǳ��ϴµ�.. ����������ƴϴ�.

	char nChar;
	printf(" scanf_s�� char �� ���� �Է¹ޱ� :  ");
	//���ڰ��� size�� ���� ������.
	//scanf_s("%*c%c", &nChar, 1);

	scanf_s(" %c", &nChar, 1);
	printf(" nChar : %c\n", nChar);

}

int main(void) {

	printf("############# ����, Hellow World ����ϱ� ############# \n");
	printf("Hellow World\n");
	printf("\n");
	
	//1
	//warningFloat();
	//2
	//getCharPutChar();
	//3
	getsPutsScanf();

	return 0;
}
