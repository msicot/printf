#include "inc/libftprintf.h"
#include <stdio.h>
#include <wchar.h>

#define _TEST_ "@moulitest: %.5u", 42
#define _TEST1_ "hello %"
#define _TEST2_ "%yyy"
#define _TEST3_ "% %"
#define _TEST4_ "T4 ->%p", 0
#define _TEST5_ "hello "

int main()
{
char* l = setlocale(LC_ALL, "");
// printf("%C\n", (char)0);
//	ft_printf("%s\n", NULL);
//while (1)
uintmax_t i = 0;
while (i < 1000)
{
	ft_printf("\n");

ft_printf("%%\n");
ft_printf("%d\n", 42);
ft_printf("%d%d\n", 42, 41);
ft_printf("%d%d%d\n", 42, 43, 44);
ft_printf("%ld\n", 2147483647);
ft_printf("%lld\n", 9223372036854775807);
ft_printf("%x\n", 505);
ft_printf("%X\n", 505);
ft_printf("%p\n", &ft_printf);
ft_printf("%20.15d\n", 54321);
ft_printf("%-10d\n", 3);
ft_printf("% d\n", 3);
ft_printf("%+d\n", 3);
ft_printf("%010d\n", 1);
ft_printf("%hhd\n", 0);////
ft_printf("%jd\n", 9223372036854775807);
ft_printf("%zd\n", 4294967295);
ft_printf("%\n");
ft_printf("%U\n", 4294967295);
ft_printf("%u\n", 4294967295);
ft_printf("%o\n", 40);
ft_printf("%%#08x\n", 42);
ft_printf("%x\n", 1000);
ft_printf("%#X\n", 1000);
ft_printf("%s\n", NULL);
ft_printf("%S\n", L"ݗݜशব");
ft_printf("%50.45C\n", (char)0);
ft_printf("%0.45C\n", (char)0);
ft_printf("%.45C\n", (char)0);
ft_printf("%55C\n", (char)0);
ft_printf("%50C\n", (char)0);
ft_printf("%50.45C\n", (char)0);
ft_printf("%S\n", (char)0);ft_printf("%50C\n", (char)0);
ft_printf("%S\n", (char)0);ft_printf("%.10C\n", (char)0);
ft_printf("%S\n", (char)0);
ft_printf("%C\n", (char)0);
ft_printf("%S\n", (char)0);
ft_printf("%s%s\n", "test", "test");
ft_printf("%s%s%s\n", "test", "test", "test");
ft_printf("%C\n", 15000);
ft_printf("%C\n", (char)0);

ft_printf("\n");
ft_printf("%%\n");
ft_printf("%d\n", 42);
ft_printf("%d%d\n", 42, 41);
ft_printf("%d%d%d\n", 42, 43, 44);
ft_printf("%ld\n", 2147483647);
ft_printf("%lld\n", 9223372036854775807);
ft_printf("%x\n", 505);
ft_printf("%X\n", 505);
ft_printf("%p\n", &ft_printf);
ft_printf("%20.15d\n", 54321);
ft_printf("%-10d\n", 3);
ft_printf("% d\n", 3);
ft_printf("%+d\n", 3);
ft_printf("%010d\n", 1);
ft_printf("%hhd\n", 0);
ft_printf("%jd\n", 9223372036854775807);
ft_printf("%zd\n", 4294967295);
ft_printf("%\n");
ft_printf("%U\n", 4294967295);
ft_printf("%u\n", 4294967295);
ft_printf("%o\n", 40);
ft_printf("%%#08x\n", 42);
ft_printf("%x\n", 1000);
ft_printf("%#X\n", 1000);
ft_printf("%s\n", NULL);
ft_printf("%S\n", L"ݗݜशব");
ft_printf("%s%s\n", "test", "test");
ft_printf("%s%s%s\n", "test", "test", "test");
ft_printf("%C\n", 15000);
ft_printf("\n");
ft_printf("%%\n");
ft_printf("%d\n", 42);
ft_printf("%d%d\n", 42, 41);
ft_printf("%d%d%d\n", 42, 43, 44);
ft_printf("%ld\n", 2147483647);
ft_printf("%lld\n", 9223372036854775807);
ft_printf("%x\n", 505);
ft_printf("%X\n", 505);
ft_printf("%p\n", &ft_printf);
ft_printf("%20.15d\n", 54321);
ft_printf("%-10d\n", 3);
ft_printf("% d\n", 3);
ft_printf("%+d\n", 3);
ft_printf("%010d\n", 1);
ft_printf("%hhd\n", 0);
ft_printf("%jd\n", 9223372036854775807);
ft_printf("%zd\n", 4294967295);
ft_printf("%\n");
ft_printf("%U\n", 4294967295);
ft_printf("%u\n", 4294967295);
ft_printf("%o\n", 40);
ft_printf("%%#08x\n", 42);
ft_printf("%x\n", 1000);
ft_printf("%#X\n", 1000);
ft_printf("%s\n", NULL);
ft_printf("%S\n", L"ݗݜशব");
ft_printf("%s%s\n", "test", "test");
ft_printf("%s%s%s\n", "test", "test", "test");
ft_printf("%C\n", 15000);
i++;}

/*	 printf(_TEST_);ft_putchar('\n');
	 ft_printf(_TEST_); ft_putchar('\n');
	ft_putchar('\n');	 

	 ft_putchar('\n');*/
//	printf("<---F(x) %d\n", printf(_TEST_));
//	printf("<---USR  %d\n\n",ft_printf(_TEST_));
	
return(0);


}
