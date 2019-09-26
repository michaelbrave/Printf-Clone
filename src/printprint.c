/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:09:59 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 23:03:21 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printprint(t_all *all)
{
	all->retsize = all->size + all->retsize;
	write(1, all->toprint, all->size);
	all->size = 0;
}

int		len_figure(int newlen, int len, char *s1)
{
	if (s1 == '\0')
		len++;
	if (newlen == len)
		len = ft_strlen(s1);
	return (len);
}

char	*ft_strjoin_len(char *s1, char *s2, int len)
{
	char		*str;
	int			newlen;
	int			i;

	i = 0;
	newlen = len;
	if (*s2 == '\0')
		newlen++;
	len = len_figure(newlen, len, s1);
	str = (char *)malloc(sizeof(char) * (newlen + 1));
	while (len > i && s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (newlen > i)
	{
		str[i] = s2[i - len];
		i++;
	}
	free(s1);
	free(s2);
	str[i] = '\0';
	return (str);
}

void	make_queue(t_all *all)
{
	size_t	i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (all->spec == '0')
		return ;
	tmp = malloc(sizeof(char *) * (all->here_percent + 1));
	ft_bzero(tmp, all->here_percent + 1);
	while (all->here_percent > i && all->str[all->i] != '\0')
	{
		tmp[i] = all->str[all->i];
		all->i++;
		all->size++;
		i++;
	}
	tmp2 = ft_strjoin(all->toprint, tmp);
	free(all->toprint);
	all->toprint = tmp2;
	printprint(all);
	free(tmp);
	free(tmp2);
	all->toprint = 0;
}
