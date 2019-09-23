/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:09:59 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/22 14:10:00 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void printprint(t_all *all)
{
    size_t i = 0;
    all->size = 0;

    if (all->toprint == 0 || all->toprint == NULL)
        return;
    while(all->toprint[i])
    {
        ft_putchar(all->toprint[i]);
        i++;
    }
    all->size = i;
}

