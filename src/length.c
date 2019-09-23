/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:01:28 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/22 17:01:29 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char   *length(t_all *all, char *str, int base)
{
    void *holder;

    holder = (va_arg(all->args, void *));
    if ((long long)holder < 0)
        all->neg = 1;
    if (all->length == 0) // int, default
        str = make_int(all, str, holder, base);
    else if (all->length == 1) // h - short
        str = make_short(all, str, holder, base);
    else if (all->length == 2) // hh - char?
        str = make_char(all, str, holder, base);
    else if (all->length == 3) // l - long
        str = make_long(all, str, holder, base);
    else if (all->length == 4) // ll - long long
        str = make_long_long(all, str, holder, base);
    else if (all->length == 5) // L - long double
        str = make_long_double(all, str, holder, base);
    else if (all->length == 6) // unsigned
        str = make_unsigned(all, str, holder, base);
    else if (all->length == 7) // unsigned long
        str = make_unsigned_long(all, str, holder, base);
    if (all->neg == 1) //|| str[0] == '-'
        check_negative(all, str);
    return(str);
}

char *make_int(t_all *all, char *str, void *holder, int base) //default
{
    int i;

    i = (wint_t)holder;
    if (i > INT_MAX)
        i = i - INT_MAX;
    str = ft_strnew(ft_numplace((wint_t)i, base));
    str = ft_itoa_base((wint_t)i, 10);

    return(str);
}

char *make_short(t_all *all, char *str, void *holder, int base) //h
{
    short h;

    h = (short)holder;
    if (h > SHRT_MAX)
        h = h - SHRT_MAX;
    str = ft_strnew(ft_numplace(h, base));
    str = ft_itoa_base(h, base);
    free(str);

    return(str);
}

char *make_char(t_all *all, char *str, void *holder, int base) //hh
{
    char c;
    char *str2; //might not be necissary

    c = (char)holder;
    if (c > CHAR_MAX)
        c = c - CHAR_MAX;
    str2 = ft_strnew(2);
    str2[0] = c;
    str2[1] = '\0';

    return(str2);
}

char *make_long(t_all *all, char *str, void *holder, int base) //l
{
    long l;

    l = (long)holder;
    if (l > 4294967296)
        l = l - 4294967296;
    str = ft_strnew(ft_numplace(l, base));
    str = ft_itoa_base(l, base);

    return(str);
}
