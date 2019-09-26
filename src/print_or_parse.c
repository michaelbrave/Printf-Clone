/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_or_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:09:51 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 21:00:43 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_percent(t_all *all)
{
	size_t	i;

	i = all->i;
	while (STR(i) != '\0' && STR(i) != '%')
		i++;
	all->here_percent = i - all->i;
}

void	print_or_parse(t_all *all)
{
	while (all->str[all->i])
	{
		find_percent(all);
		if (all->here_percent == 0)
		{
			all->spec = 0;
			all->here_spec = 0;
			find_spec(all, 1);
			if (all->spec == 0)
				return ;
			finder_main(all);
			switch_do(all);
		}
		else
			make_queue(all);
	}
}
