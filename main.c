#include "inc/libftprintf.h"
#include <stdio.h>





#define _TEST_ "t0 -->%#10llX<--", (unsigned long long)-1248759650
#define _TEST1_ "t1 -->%7.5X<- et !", 0xab
//#define _TEST1_ "t1 -->%#.0x<--", 0
#define _TEST2_ "t2 -->%#7.5X<- et !", 0xab
#define _TEST3_ "t3 -->%0##0.4X<->%#4.2x<-et cest fini<-", 0x037a, 0x9e
#define _TEST4_ "t4 -->coco et  ->%-#-#--4X<- titi->%#012x<-", 12, -874
#define _TEST5_ "t5 -->%0#10.5x<--", 12345
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
	

	printf(" %d\n", printf(_TEST_));
	printf(" %d\n\n",ft_printf(_TEST_));
// while(1)
//		i = 1;
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
*/
//	printf("pf= %d\n", printf(_TEST1_));
//	printf("pf= %d\n", printf(_TEST2_));
//	printf("pf= %d\n", printf(_TEST3_));

//	while (1)		
//		i = 1;
/*	printf("\nThis is a test%d\n", k);
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
