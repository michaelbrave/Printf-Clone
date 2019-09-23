/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:50 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:09:52 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     do_s(t_all *all) // converts to str
{
    char *str;
    char *tmp;

    str = ft_strdup(va_arg(all->args, char *));
    if (str == NULL)
        str = ft_strdup("(null)");
    str = format_master(all, str);
    tmp = all->toprint;
    all->toprint = ft_strjoin(tmp, str);
    free(str);
    free(tmp);
    all->size = ft_strlen(all->toprint);

    return(0);
}