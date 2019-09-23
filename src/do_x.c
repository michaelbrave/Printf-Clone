/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:05 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:10:07 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *x_capitolize(char *tmp)
{
    int i;

    i = 0;
    while (tmp[i])
    {
        if (tmp[i] >= 'a' && tmp[i] <= 'z')
            tmp[i] = tmp[i] - 32;
        i++;
    }
    return (tmp);
}

int     do_x(t_all *all) // converts to hex
{
    char *str;
    char *tmp;

    str = NULL;
    if (all->length == 0)
        all->length = 6;
    str = length(all, str, 16);
    str = format_master(all, str);
    if (all->spec == 'X')
        str = x_capitolize(str);
    tmp = all->toprint;
    all->toprint = ft_strjoin(tmp, str);
    free(str);
    free(tmp);
    all->size = ft_strlen(all->toprint);

    return(0);
}