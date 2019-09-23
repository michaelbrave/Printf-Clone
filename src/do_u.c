/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:57 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:09:58 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*make_unsigned_long(t_all *all, char *str, void *holder, int base)
{
    unsigned long u;

    u = (unsigned long long)holder;//how to implement max? 4294967295
    if (u >= 18446744073709551611)
        u = u - 18446744073709551611;
    str = ft_strnew(ft_numplace(u, base));
    str = ft_itoa_unsigned(u, base);

    return(str);
}

int     do_u(t_all *all) // converts to unsigned int
{
    char *str;
    char *tmp;

    str = NULL;
    if (all->length == 0)
        all->length = 6;
    else if (all->length == '3')
        all->length = 7;
    str = length(all, str, 10);
    str = format_master(all, str);
    tmp = all->toprint;
    all->toprint = ft_strjoin(tmp, str);
    free(str);
    free(tmp);
    all->size = ft_strlen(all->toprint);

    return(0);
}