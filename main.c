#include "inc/libftprintf.h"
#include <stdio.h>
#include <wchar.h>

#define _TEST_ "->ca%----4cva %10c%-c ??<-", '\0'  
#define _TEST1_ "ca%-4c %1c va %10c%-c ?? lol", '\0', '\n', (char)564, 0
#define _TEST2_ "t2 -> %12lc <-- et !", 127
#define _TEST3_ "t3 ->%-c ?<-", 0
#define _TEST4_ "t4 ->\0%-5.3s ??<--", "yoooo"
#define _TEST5_ "t1 ->%8C et coco %10C titi %lc", 3250, 0x11ffff, 'a'
int main()
{
	unsigned char t = 42;
	char a = '*';
	char *b = " world";
	char *c = "!!!";
	
	intmax_t i = -922;//3372036854775808;
//	printf("\n \tTest itoa\n i->%s<-\n\n", ft_itoa_max(i));
	int j = 992;
	intmax_t k = 42;

char* l = setlocale(LC_ALL, "");
	if (l == NULL) 
		printf("Locale not set\n");
	else 
		printf("Locale set to %s\n", l);
	/*	
	printf("X->%c<-\n", 0);
	ft_printf("mine->%c<-\n",0);
printf("Y->%c<-\n", 0);
printf("Z->%c<-\n", NULL);
printf("A->%s<-\n", "\0");
printf("B->%c<-\n", 0);
*/


	printf(" %d\n", printf(_TEST_));
	printf(" %d\n\n",ft_printf(_TEST_));
 //while(1)
	//	i = 1;
	printf(" %d\n", printf(_TEST1_));
	printf(" %d\n\n",ft_printf(_TEST1_));
	
	printf(" %d\n", printf(_TEST2_));
	printf(" %d\n\n",ft_printf(_TEST2_));
	
	printf(" %d\n", printf(_TEST3_));
	printf(" %d\n\n",ft_printf(_TEST3_));

	printf(" %d\n", printf(_TEST4_));
	printf(" %d\n\n",ft_printf(_TEST4_));
	printf(" %d\n", printf(_TEST5_));
	printf(" %d\n",ft_printf(_TEST5_));
//while (1)
//	i = 1;
/*
//LIM
	printf(" %d\n", printf(_TEST6_));
	printf(" %d\n\n",ft_printf(_TEST6_));
	printf(" %d\n", printf(_TEST7_));
	printf(" %d\n\n",ft_printf(_TEST7_));

//	printf("pf= %d\n", printf(_TEST1_));
//	printf("pf= %d\n", printf(_TEST2_));
//	printf("pf= %d\n", printf(_TEST3_));

//	while (1)		
//		i = 1;
	printf("\nThis is a test%d\n", k);
	printf("blank '+'%+++++++++d\n", k);
	printf("Multiples - %------5s\n", a);
	printf("This is a test%     d\n", k);
	printf("This is a test%d\n", k);
	printf("%+-5dend\n", i);
 	printf("This is a test%6d\n", k);
	printf("This is a test%-6d\n", k);
	printf("This is a test%06d\n", k);
	printf("test espace =>% 6d\n", k);
	printf("This is a test%6d\n", k);

	printf("%+--5dend\n", i);
	printf("% dend\n", i);*/
	return (0);
}
