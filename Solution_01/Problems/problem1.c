#include<stdio.h>

void problem03_01() {

	printf("³ªÀÌ¸¦ ÀÔ·ÂÇÏ¼¼¿ä. : ");
	int age;

	// ÀÌ·¸°Ô scanf¾²·Á¸é ÀÔ·Âµµ "Input: 3" ÀÌ·±½ÄÀ¸·Î ÀÛ¼ºÇØ¾ß ÇÔ
	// ½ºÆäÀÌ½ºµµ ÁÖÀÇÇØ¾ß ÇÔ !! 
	//scanf_s("Input: %d", &age);

	// ÀÔ·Â¹öÆÛ¿¡ \n Ã³¸®ÇÏ±âÀ§ÇØ¼­ %*cÃß°¡ Çß´Ù.
	// scanf()ÇÔ¼öÀÇ Çü½Ä ¹®ÀÚ¿¡¼­ %±âÈ£¿Í Çü½Ä ¹®ÀÚ »çÀÌ¿¡ À§Ä¡ÇÑ º°Ç¥(*)´Â '¹ö¸²'À» ÀÇ¹ÌÇÑ´Ù.
	scanf_s("%d%*c", &age);

	printf("ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä. : ");
	char name[12];
	gets_s(name, sizeof(name));


	printf("´ç½ÅÀÇ ³ªÀÌ´Â %d»ìÀÌ°í ÀÌ¸§Àº '%s'ÀÔ´Ï´Ù.\n", age, name);

	char ch = 0;

	printf(" charÇÑ¹®ÀÚ¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ");

	// %cÀÇ °æ¿ì , scanf_s()ÇÔ¼ö¿¡¼­´Â ÁÖ¼Òº¯¼ö, ¹ÙÀÌÆ®Å©±â´ÜÀ§¸¦ ÀÎÀÚ·Î ³Ñ°ÜÁÖ¾î¾ß ÇÑ´Ù.
	scanf_s("%c", &ch, sizeof(ch));
	printf(" ÀÔ·ÂÇÑ ¹®ÀÚ´Â %c ÀÔ´Ï´Ù. \n", ch);

}

void problem04_01() {
	
	int a, b;
	printf("Á¤¼ö a,b¸¦ ÀÔ·ÂÇÏ¼¼¿ä. a,b ÇüÅÂ·Î ÀÔ·ÂÇÏ¼¼¿ä! \n");
	scanf_s("%d,%d",&a,&b);
	printf("µÎ Á¤¼öÀÇ Æò±ÕÀº %.2f ÀÔ´Ï´Ù", (a + b) / 2.0f );

}

void problem04_02() {
	
	int second = 0;
	
	printf("ÃÊ¸¦ ÀÔ·ÂÇÏ¼¼¿ä. : ");
	scanf_s("%d", &second);
	
	int input, hour, minute;

	// Ã³À½ ÀÔ·Â ÃÊ
	input = second;
	
	// ½Ã°£´ÜÀ§·Î ³ª´©·Á¸é 60 * 60 ÀÌ´Ï±ñ 3600 ÃÊ..
	hour = second/3600;

	second %= 3600;
	
	// ºĞ´ÜÀ§´Â 60ÃÊ.
	minute = second / 60;

	second %= 60;
	
	printf("%dÃÊ´Â %02d½Ã°£ %02dºĞ %02dÃÊ ÀÔ´Ï´Ù.", input, hour, minute, second);

}

void basic() {

	int nInput, nTotal = 0;

	printf(" Ã¹ ¹øÂ° ¼ıÀÚ ÀÔ·Â : ");
	scanf_s("%d", &nInput);
	nTotal += nInput;
	printf(" µÎ ¹øÂ° ¼ıÀÚ ÀÔ·Â : ");
	scanf_s("%d", &nInput);
	nTotal += nInput;
	printf(" ¼¼ ¹øÂ° ¼ıÀÚ ÀÔ·Â : ");
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

// ¸¶½ºÅ©¿¬»êÀÌ¶õ
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

	// " '=': ¿ŞÂÊ ÇÇ¿¬»êÀÚ´Â l-valueÀÌ¾î¾ß ÇÕ´Ï´Ù. " ÇÏ¸é¼­ ¿¡·¯³² !!
	// nInput <= 10 ? nSelect = 10 : nSelect = 20;
		
	// nInput <= 10 ? (nSelect = 10) : (nSelect = 20);
	// nInput <= 10 ? nSelect = 10 : nSelect;

	printf("%d\n", nSelect);
}

void select() {
	int tall;

	printf(" Å°¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä : ");
	scanf_s("%d", &tall);

	printf(" °á°ú : %s", tall >= 150 ? "ÇÕ°İ" : "ºÒÇÕ°İ");
}

void tournoment() {


	int nMax = 0;
	int a, b, c;
	
	scanf_s("%d,%d,%d", &a, &b, &c);

	nMax = a > b ? a : b;
	nMax = nMax > c ? nMax: c;

	printf("MAX : %d\n", nMax);

}

<<<<<<< HEAD
<<<<<<< HEAD
void arrayTest() {

	int arr1[] = { 1,2,3 };
	int arr2[] = { 4,5,6 };

	// arr1 = arr2; // ¾ÈµÊ
	*arr1 = arr2; // µÇ´Âµ¥.. ³»°¡ ÀÇµµÇÑ ´ë·Î¾ÈµÇ³×.. ±×³É arr1[0]¹øÂ° ¿ä¼Ò¿¡ .. arr2ÀÇ ÁÖ¼Ò°ªÀÌ µé¾î°¡´Â±º..

	for (int i = 0; i < 3; i++) {
		printf("arr1[%d] = %d\n", i , arr1[i]);
		printf("arr2[%d] = %d\n", i , arr2[i]);
	}
=======
=======
>>>>>>> 98f29eb002fd5213d4c1bde031f9aa87685bde81
void problem06_02() {

	int age;

	printf(" ³ªÀÌ¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä : ");
	scanf_s("%d", &age);

	int won = 1000;

	if (age < 20) won *= (0.75);

	printf("ÃÖÁ¾¿ä±İ : %d", won);
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
		printf("%dth\n", i); // th±×³É ¹®ÀÚ³× ¤Ñ..¤Ñ
	}

	i = 0;

	for (; i < 5; i++) {
		printf("[%d] ÃÊ±â È­ i »ı·« °¡´ÉÇÔ ! ÃÊ±ê°ª 0ºÎÅÍ °Ú³×.\n", i );
	}


	for (i = 0; i < 5;) {
		printf("[%d] °è¼ö±â »ı·«ÇÏ¸é.. ¹«ÇÑ·çÇÁ ºüÁö³× ¤Ñ..¤Ñ ÀÚµ¿ 1Áõ°¡ ¾ÈµÇ´Â±º ! !\n",i);
		break;
	}

	for (;; ) {
		printf(" ¹« . ÇÑ. ·ç . ÇÁ . !! ");
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

	printf(" 1~10±îÁöÀÇ ÇÕ : %d ", sum);

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

	printf(" 4ÀÇ ¹è¼ö´Â ÃÑ %d °³ ÀÌ°í, ÃÑÇÕÀº %d ÀÔ´Ï´Ù.", cnt , sum);

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
<<<<<<< HEAD

>>>>>>> f31705a30df046a51afe0a1ea535cb357e0f0d3f
}

=======
}

void arrayTest() {

	int arr1[] = { 1,2,3 };
	int arr2[] = { 4,5,6 };

	// arr1 = arr2; // ¾ÈµÊ
	*arr1 = arr2; // µÇ´Âµ¥.. ³»°¡ ÀÇµµÇÑ ´ë·Î¾ÈµÇ³×.. ±×³É arr1[0]¹øÂ° ¿ä¼Ò¿¡ .. arr2ÀÇ ÁÖ¼Ò°ªÀÌ µé¾î°¡´Â±º..

	for (int i = 0; i < 3; i++) {
		printf("arr1[%d] = %d\n", i, arr1[i]);
		printf("arr2[%d] = %d\n", i, arr2[i]);
	}

	printf("arr2[0]ÀÇ ÁÖ¼Ò : %d" ,&arr2[0]);
}

void z9j9() {

	int arr[5][5] ;
	int cnt = 1;

	for (int i = 0; i < 5; i++) {

		int reverse = 0;

		if (i % 2 == 1) reverse = 1;

		if ( reverse == 0) {
			for (int j = 0; j < 5; j++) {
				arr[i][j] = cnt++;
			}
		}
		else {
			for (int j = 4; j >= 0; j--) {
				arr[i][j] = cnt++;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d\t", arr[i][j]);
		}
		putchar('\n');
	}
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 606da5d... í•¨ìˆ˜ ê°„ë‹¨í•˜ê²Œ ì¨ë³´ê¸°
void snail() {

	// ²ÀÇ®¾îº¸±â.. ´ŞÆØÀÌÃâ·Â

	int arr[5][5];

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {
			
		}

	}

}

void add(int, int);

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 98f29eb002fd5213d4c1bde031f9aa87685bde81

=======
>>>>>>> 1c1d2db... 2ì°¨ì› ë°°ì—´ ì§€ê·¸ì¬ê·¸ í’€ì–´ë³´ê¸°. .ë‚œì´ë„ë‚®ìŒ..
=======
>>>>>>> 606da5d... í•¨ìˆ˜ ê°„ë‹¨í•˜ê²Œ ì¨ë³´ê¸°
=======

<<<<<<< HEAD
>>>>>>> 18c9922... í¬ì¸í„° ì‚´ì§ì‚¬ìš©í•´ë³´ê¸° !
=======
>>>>>>> 5bb3c47... í¬ì¸í„° ì‚´ì§ì‚¬ìš©í•´ë³´ê¸° !
>>>>>>> 8be8a583a3b29cc6e8fae1621d95510eab59cb2f
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
<<<<<<< HEAD
<<<<<<< HEAD
	// survival();
	arrayTest();
	// printf("true : %d , false : %d " , 1==1 , 1==2);
=======
=======
	// survival();
	// arrayTest();
	// printf("true : %d , false : %d " , 1==1 , 1==2);
>>>>>>> 98f29eb002fd5213d4c1bde031f9aa87685bde81
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
<<<<<<< HEAD
<<<<<<< HEAD
	loopPractice4_answer();
>>>>>>> f31705a30df046a51afe0a1ea535cb357e0f0d3f
=======
	// loopPractice4_answer();
	// arrayTest();
<<<<<<< HEAD
	z9j9();
>>>>>>> 1c1d2db... 2ì°¨ì› ë°°ì—´ ì§€ê·¸ì¬ê·¸ í’€ì–´ë³´ê¸°. .ë‚œì´ë„ë‚®ìŒ..

}	
=======
	// loopPractice4_answer();
	// arrayTest();
	// z9j9();
	// add(1, 2);
	
	
}

void add(int a, int b) {
	printf("%d",a + b);
}
>>>>>>> 98f29eb002fd5213d4c1bde031f9aa87685bde81
=======
	// z9j9();
	// add(1, 2);
	
	
}

void add(int a, int b) {
	printf("%d",a + b);
}
>>>>>>> 606da5d... í•¨ìˆ˜ ê°„ë‹¨í•˜ê²Œ ì¨ë³´ê¸°
