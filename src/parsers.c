/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:48:17 by mbrave            #+#    #+#             */
/*   Updated: 2019/08/28 12:48:18 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parser(t_all *all)
{
    if ( ft_strcmp(all->copy, "%") == 0)
        return(0);
    while (all->copy[all->i] != '\0')
    {
        if (all->copy[all->i] == '%')
        {
            reinitialize(all);
            mechanics(all);
        }
        else
        {
            write(1, &all->copy[all->i], 1);
            all->size++;
        }
        all->i++;
    }

    return(all->size);
}

