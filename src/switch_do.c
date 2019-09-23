/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_do.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:11:01 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:11:02 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    switch_do(t_all *all)
{
    if(all->spec == '%')
        do_percent(all);
    else if(all->spec == 's')
        do_s(all);
    else if(all->spec == 'c')
        do_c(all);
    else if(all->spec == 'd' || all->spec == 'i')
        do_d(all);
    else if(all->spec == 'u')
        do_u(all);
    else if(all->spec == 'o')
        do_o(all);
    else if(all->spec == 'x' || all->spec == 'X')
        do_x(all);
    else if(all->spec == 'p')
        do_p(all);
    //else if(all->spec == 'f')
    //    do_f(all);
    all->i = all->here_spec;
    all->i++;
}
