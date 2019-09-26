/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:36 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 19:35:55 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all	initialize(char *format)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	all.str = format;
	return (all);
}

char	*width_padding(t_all *all, char *tmp, int len)
{
	int		i;
	char	c;

	if (all->align == '-')
		c = ' ';
	else if (all->spec == 'o' && all->align == '-')
		c = '0';
	else if ((all->align == '-' || (((NUMBER)) && all->padfill != '0')))
		c = ' ';
	else if (all->padfill == '0' && PRE && (all->precision == 0 && NUMBER))
		c = '0';
	else
		c = ' ';
	i = 0;
	if (len < 0)
		len = 0;
	while (len > i)
	{
		tmp[i] = c;
		i++;
	}
	tmp[i + 1] = '\0';
	return (tmp);
}

char	*precision_padding(t_all *all, char *tmp, int len)
{
	int		i;
	char	c;

	if (all->spec == 'o' && all->align == '-')
		c = '0';
	else if (all->padfill == '0' || NUMBER || all->spec == 'p')
		c = '0';
	else
		c = ' ';
	i = 0;
	if (len < 0)
		len = 0;
	while (len > i)
	{
		tmp[i] = c;
		i++;
	}
	tmp[i + 1] = '\0';
	return (tmp);
}

void	length_reset(t_all *all)
{
	all->length[0] = '\0';
	all->length[1] = '\0';
	all->length[2] = '\0';
	all->length[3] = '\0';
	all->length[4] = '\0';
	all->length[5] = '\0';
	all->length[6] = '\0';
}
