#include "inc/libftprintf.h"
#include <stdio.h>

//#define _TEST_ "t0 -->%llo<--", (unsigned long long)-12345612220 
#define _TEST_ "t0 -->%#01.5o<--", 129 

#define _TEST1_ "t1 -->%0#o<--",-896
#define _TEST2_ "t2 -->coco et %-#-#--24O titi%#012o", 12, -874
#define _TEST3_ "t3 -->%0#5.0o<--", j
#define _TEST4_ "t4 -->%hhd<--", 42
#define _TEST5_ "t5 -->%010.5zu<--", j
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
