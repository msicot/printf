#include "inc/libftprintf.h"
#include <stdio.h>
#include <wchar.h>

#define _TEST_ "T0->%05.2p<-", 0 
#define _TEST1_ "T1->%5.0p<-", 0
#define _TEST2_ "T2->%05p<-", 0
#define _TEST3_ "T3 >------------<%-#40.36zx>------------<", -1373977486
#define _TEST4_ "T4 ->"
#define _TEST5_ "hello "

int main()
{
	char *c = "yo";
	wchar_t	s[4];
char* l = setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
 //while(1)
	//	i = 1;
	//
	 //printf(_TEST_);ft_putchar('\n');

//	 ft_printf(_TEST_); ft_putchar('\n');
//	 ft_putchar('\n');
	printf(" %d\n", printf(_TEST_));
	printf(" %d\n\n",ft_printf(_TEST_));
	

	printf(" %d\n", printf(_TEST1_));
	printf(" %d\n\n",ft_printf(_TEST1_));
	printf(" %d\n", printf(_TEST2_));
	printf(" %d\n\n",ft_printf(_TEST2_));

	printf(" %d\n", printf(_TEST3_));
	printf(" %d\n\n",ft_printf(_TEST3_));
	printf(" %d\n", printf(_TEST4_));
	printf(" %d\n",ft_printf(_TEST4_));
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


//	ft_printf(_TEST_);
//	printf(_TEST_);

//printf(_TEST_);
//ft_putchar('\n');
printf(_TEST1_);
	ft_printf(_TEST1_);

ft_putchar('\n');
printf(_TEST2_);
	ft_printf(_TEST2_);
	
ft_putchar('\n');
printf(_TEST3_);
	ft_printf(_TEST3_);

ft_putchar('\n');
printf(_TEST4_);
	ft_printf(_TEST4_);



	printf("%+--5dend\n", i);
	printf("% dend\n", i);*/

	return (0);
}
