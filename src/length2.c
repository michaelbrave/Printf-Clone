/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:01:34 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/22 17:01:36 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *make_long_long(t_all *all, char *str, void *holder, int base) //ll
{
    long long l;

    l = (long long)holder;
    if (l > LONG_MAX)
        l = l - LONG_MAX;
    str = ft_strnew(ft_numplace(l, base));
    str = ft_itoa_base(l, base);

    return(str);
}

char *make_long_double(t_all *all, char *str, void *holder, int base) //L
{
    long double d;

    d = (long long)holder;
    if (d > ULONG_MAX)
        d = d - ULONG_MAX;
    str = ft_strnew(ft_numplace(d, base));

    return(str);
}

char *make_unsigned(t_all *all, char *str, void *holder, int base) //make unsigned
{
    unsigned long u;

    u = (unsigned long)holder;//how to implement max? 4294967295
    if (u >= 4294967296)
        u = u - 4294967296;
    str = ft_strnew(ft_numplace(u, base));
    str = ft_itoa_unsigned(u, base);

    return(str);
}

char *check_negative(t_all *all, char * str)
{
    int i;

    i = -1;
    all->neg = 0;
    if (str[0] == '-')
    {
        while(str[++i])
            str[i] = str[i + 1];
        str[i] = '\0';
        all->neg = 1;
    }
    return(str);
}

//make double?
//mak unsigned long?
