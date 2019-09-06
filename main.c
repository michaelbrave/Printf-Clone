//#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
int main()
{   unsigned long d = 23465407;
    //ft_printf("Hello %d", d);
    printf("wint_t:%d wchar_t:%d\n", sizeof(float), sizeof(wchar_t));
    //printf("%.*d %c %s\n", 12, 1, 's', itoa(123));
    printf("%3$d %1$o %1$x", 1);
    return(0);
}
