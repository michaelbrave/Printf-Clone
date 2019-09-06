/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:48:17 by mbrave            #+#    #+#             */
/*   Updated: 2019/08/28 12:48:18 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all   *parse_format(t_all *all) //probably replace this whole thing
{
    size_t i;

    i = 0;
    while (all->format_table[i])
    {
        while (all->format_table[i] == all->copy2[all->i])
        {
            while(all->copy2[all->i] == '-' && all->i++)
                all->format[0] = '-';
            while(all->copy2[all->i] == '+' && all->i++)
                all->format[1] = '+';
            while(all->copy2[all->i] == ' ' && all->i++)
                all->format[2] = ' ';
            while(all->copy2[all->i] == '0' && all->i++)
                all->format[3] = '0';
            while(all->copy2[all->i] == '#' && all->i++)
                all->format[4] = '#';
            i = 0;
        }
        i++;
    }
    return (all);
}

t_all   *parse_width(t_all *all) //porbably replace this too
{
    while (all->copy2[all->i] >= '0' && all->copy2[all->i] <= '9')
    {
        all->width_predot *= 10;
        all->width_predot += (all->copy2[all->i] - 48); //i forget why 48
        all->i++;
    }
    return (all);
}

t_all *parse_precision(t_all *all)
{
    while (all->copy2[all->i] == '.')
    {
        all->i++;
        all->precision_afterdot = 0;
    }
    while (all->copy2[all->i] >= '0' && all->copy2[all->i] <= '9')
    {
        all->precision_afterdot *= 10;
        all->precision_afterdot += (all->copy2[all->i] - 48);
        all->i++;
    }
    return (all);
}

t_all *parse_arg(t_all *all)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (all->arg_table[i])
    {
        while (all->arg_table[i] == all->copy2[all->i])
        {
            all->arg_table[j] = all->copy2[all->i];
            all->arg_table[j + 1] = '\0';
            all->i++;
            j++;
        }
        i++;
    }

    return (all);
}

t_all *parse_flags(t_all *all)
{
    size_t  i;

    i = 0;
    while (all->flag_table[i])
    {
        if (all->flag_table[i] == all->copy2[all->i])
            all->flag = all->flag_table[i];
        i++;
    }
    return(all);
}

