#include "stdio.h"

void    print(char *s)
{
    printf("%s\n", s);
}

int        lol(int n)
{
    if (n == 69)
        return (420);
    return (n);
}

int main(void)
{
    char *s = "goodbye world";
    void    (*fun)(char *);
    int        (*num)(int);

    fun = &print;
    fun(s);
    num = lol;
    printf("%d\n", num(69));
    return (0);
}