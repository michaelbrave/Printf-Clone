/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:36 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:10:38 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all	*initialize(char *format)
{
    t_all *all;
    if (!(all = (t_all*)malloc(sizeof(t_all)))) //might be the wrong spot? should be in printf?
	    return (NULL);
    ft_bzero(all, sizeof(t_all));
    all->str = format;

    return(all);
}

void    make_queue(t_all *all) // what about when I start with the thing?
{
    size_t i = 0;
    char *tmp;
    char *tmp2;

    tmp = malloc(sizeof(char *) * (all->here_percent + 1));
    ft_bzero(tmp, all->here_percent + 1);
    while (all->here_percent > i && all->str[all->i] != '\0')
    {
        tmp[i] = all->str[all->i];
        all->i++;
        i++;
    }
    tmp2 = ft_strjoin(all->toprint, tmp);
    all->toprint = tmp2;
    free(tmp);
    all->size = (ft_strlen(all->toprint));
}

char *width_padding(t_all *all, char *tmp, int len)
{
    int i;
    char c;
    if (all->align == '-')
        c = ' ';
    else if (all->spec == 'o' && all->align == '-')
        c = '0';
    else if ((all->align == '-' || (((NUMBER)) && all->padfill != '0')))
        c = ' ';
    else if (all->padfill == '0' && all->precactiv == 0)
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
    tmp[i + 1] ='\0';

    return(tmp);
}

char *precision_padding(t_all *all, char *tmp, int len)
{
    int i;
    char c;
    if (all->spec == 'o' && all->align == '-')
        c = '0';
    else if (all->padfill == '0' || NUMBER)
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
    tmp[i + 1] ='\0';

    return(tmp);
}