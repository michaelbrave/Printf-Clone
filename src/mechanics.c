/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:19:00 by mbrave            #+#    #+#             */
/*   Updated: 2019/08/29 13:19:02 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int mechanics(t_all *all)
{
    all->i++;
    parse_convert(all);
    parse_width(all);
    parse_precision(all);
    parse_arguments(all);
    parse_specifier(all);
    display(all);
    return(all->size);
}