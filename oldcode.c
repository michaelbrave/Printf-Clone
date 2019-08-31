#include "ft_printf.h"


void stringparse(const char *fmt, t_all *holding)
{
    char *str;
    int i = 0;

    while(fmt[i] != '%')
    {
        i++;
    }
    holding->string = (char*)malloc((sizeof(char) * i) +1);
    //holding->flagbearer[hash] = //is that how it works?
}

//beginning of flags

// #
//	if(fmt[i] == '#') /*alternate form - branching options based on format*/
	int flaghash(const char *fmt, t_flags *flagbearer)
    {
        int hash = 0;

        return(hash);
    }
    
// -
//	if(fmt[i] == '-') /*left adjustment*/
	int flagdash(const char *fmt, t_flags *flagbearer)
    {
        int dash = 0;

        return(dash);
    }
// +
//	if(fmt[i] == '+') /*signed*/
	int flagplus(const char *fmt, t_flags *flagbearer)
    {
        int plus = 0;

        return(plus);
    }
// ' '
//	if(fmt[i] == ' ') /*blank left before a positive number, + overrides this */
	int flagspace(const char *fmt, t_flags *flagbearer)
    {
        int space = 0;

        return(space);
    }
// 0
//	if(fmt[i] == '0') /* no padding, - overrides */
	int flagzero(const char *fmt, t_flags *flagbearer)
    {
        int zero = 0;

        return(zero);
    }
// 0-9
	int flagnumber(const char *fmt, t_flags *flagbearer)
    {
        int predot = 0;

        return(predot);
    }
// .0-9
	int flagperiod(const char *fmt, t_flags *flagbearer)
    {
        int afterdot = 0;

        return(afterdot);
    }

// end of flags

// beginning of length modifiers


//hh - integer conversion corresponds to a signed or unsigned char

//h - integer conversion corresponds to a short int or unsigned short int

//l - integer conversion corresponds to a long int or unsigned long int

//ll - integer conversion corresponds to a long long int or unsigned long long int

//L - conversion corresponds to a long double argument - same as ll?

//j - integer conversion corresponds to a intmax_t or uintmax_t (bonus)

//z - integer conversion corresponds to a size_t or ssize_t (bonus)

//t - integer conversion corresponds to a ptrdiff_t (bonus)


// end of length modifiers

void converter (const char *fmt, t_all *holding)
{
    int i = 0;

    if (fmt[i] == '%') /*[character]%[parameter][flags][width][.precision][length][type]*/
    {
        i++;

        if (fmt[i] == '%') /* %% means print a percent sign */
        {
            ft_putchar('%');
        }
        if (fmt[i] == 'd' || fmt[i] == 'D') //decimal integer signed //test for max and min value
        {
            holding->string = va_arg(argp, void *);
            ft_putstr(ft_itoa((int)holder));
        }
        if (fmt[i] == 'i' || fmt[i] == 'I') //integer (base 10) signed //test with limits.h
        {
            holding->string = va_arg(argp, void *);
            ft_putstr(ft_itoa((int)holder));
        }
        if (fmt[i] == 'o' || fmt[i] == 'O') //unsigned octal
        {
            holding->string = va_arg(argp, void *);
            ft_putstr(ft_itoa_unsigned((unsigned int)holder, 8)); //testing
        }
        if (fmt[i] == 'x' || fmt[i] == 'X') //hexadecimal (base 16) unsigned //capitol makes capitol hex
        {
            holding->string = va_arg(argp, void *);
            ft_itoa_base((int)holder, 16);
        }
        if (fmt[i] == 'u' || fmt[i] == 'U') //unsigned decimal (integer) number
        {
            holding->string = va_arg(argp, void *);
            ft_putstr(ft_itoa_unsigned((unsigned int)holder, 10));
        }
        if (fmt[i] == 'c' || fmt[i] == 'C') //character
        {
            holding->string = va_arg(argp, void *);
            ft_putchar((char)holder);
        }
        if (fmt[i] == 's' || fmt[i] == 'S') //strings
        {
            holding->string = va_arg(argp, void *);
            ft_putstr((char*)holder);
        }
    //	if (fmt[i] == 'f' || fmt[i] == 'F') //floating point number
    //	if (fmt[i] == 'p' || fmt[i] == 'P') //memory address (in hex)
    
    //	if (fmt[i] == 'e' || fmt[i] == 'E') //exponential floating point number //bonus
    //	if (fmt[i] == 'g' || fmt[i] == 'G') // not needed //bonus
    //	if (fmt[i] == 'n') // not needed
    //	if (fmt[i] == 'lu') // do I need it?

    } //end of checking for percent
    else if (fmt[i])
    {
        ft_putchar(fmt[i]);
    }
}