#include<stdio.h>

int main(void) {

	printf("############# ����, Hellow World ����ϱ� ############# \n");
	printf("Hellow World\n");
	printf("\n");

	
	// float������ ���輺
	printf("############# Float������ ���輺 ############# \n: ���������� ũ�⶧����(128����) ����� ������ �߻� ��, �Ǽ� �ڷ����� double��� ���� \n");
	// - �������� �Ȱ��� ����.
	printf("2147483648.0F      : %f\n", 2147483648.0F);
	printf("2147483648.0F - 20 : %f\n", 2147483648.0F - 20 );
	printf("2147483648.0F - 40 : %f\n", 2147483648.0F - 40 );
	printf("2147483648.0F - 60 : %f\n", 2147483648.0F - 60) ;
	printf("2147483648.0F - 64 : %f\n", 2147483648.0F - 64) ;
	printf("2147483648.0F - 65 : %f\n", 2147483648.0F - 65);
	printf("\n");
	printf("############# ���ڿ��� ���ڹ迭. �� ǥ���� ����. ############# \n") ;

	char szBuffer[12] = { 'H' , 'e' , 'l' };
	char szBuffer2[12] = { "Hel" };

	printf("szBuffer : ");
	puts(szBuffer);
	printf("szBuffer2 : ");
	puts(szBuffer2);

	printf("\n");
	printf("############# getChar, putChar ����غ��� ############# \n");
	
	printf(" getChar�� �Է� �Լ� : " );

	// getChar�� Buffer�� �����Ͱ� �ִٸ� �ϳ��� �����´�.
	// Buffer�� �����Ͱ� ���ٸ� �Է¹ް�, �ٷ� �ϳ��� �����´�.	    
	char input = getchar();

	printf(" putChar�� ��� �Լ� ! \n");

	int seq = 1;

	while (input != '\n') {
		printf("%d ��° input �� : ",seq);
		putchar(input);
		printf("\n");
		seq++;
		input = getchar();
	}

	return 0;
}