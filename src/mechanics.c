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

t_all   *switch_do(t_all *all)
{
    char    *flag;

    flag = &all->flag_table;
    if (*flag == 'd' || *flag == 'i' || *flag == 'D')
        do_d(all);
    else if (*flag == 'c' || *flag == 'C')
        do_c(all);
    else if (*flag == 's' && ft_strcmp(all->flag_table, "l") == 0)
        do_ws(all);
    else if (*flag == 'S')
        do_ws(all);
    else if (*flag == 's')
        do_s(all);
    else if (*flag == 'u' || *flag == 'U')
        do_u(all);
    else if (*flag == 'x' || *flag == 'X')
        do_x(all);
    else if (*flag == 'o' || *flag == 'O')
        do_o(all);
    else if (*flag == 'p')
        do_p(all);
    else
        do_other(all);
    return(all);
}

//can turn this into a function array to cycle through to save space?
int mechanics(t_all *all)
{
    all->i++;
    parse_format(all);
    parse_width(all);
    parse_precision(all);
    parse_arg(all);
    parse_flags(all);
    switch_do(all);
    return(all->size);
}

int	parser(t_all *all)
{
    if (ft_strcmp(all->copy, "%") == 0) //character handler instead
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