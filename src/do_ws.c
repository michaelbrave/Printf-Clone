/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:03:30 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/01 14:03:32 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		char_len(wchar_t c)
{
	int len;

	if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

static wchar_t	*wstrndup(wchar_t *s1, size_t n)
{
	wchar_t	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		exit(-1);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static wchar_t	*wstrdup(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, len));
}

static t_all	*do_null(t_all *all)
{
	wchar_t		*s;
	int			i;

	i = 0;
	s = wstrdup(L"(null)");
	if (all->precision_afterdot > -1)
	{
		while (s[i] && all->precision_afterdot-- > 0)
			do_wchar(s[i++], all);
	}
	else
	{
		while (s[i])
			do_wchar(s[i++], all);
	}
	free(s);
	return (all);
}

t_all			*do_ws(t_all *all)
{
	wchar_t		*s;
	int			i;
	int			j;
	int			len;

	i = 0;
	len = 0;
	if (!(s = (wchar_t *)va_arg(all->args, wchar_t *)))
		return (do_null(all));
	while (s[i] && !(j = 0))
	{
		if (all->precision_afterdot > -1 && (len + char_len(s[i])) > all->precision_afterdot)
			break ;
		len += char_len(s[i++]);
	}
	if (all->format[3] == '0' && all->format[0] != '-')
		do_gap(all, '0', all->width_predot - len, 1);
	else if (all->format[0] != '-')
		do_gap(all, ' ', all->width_predot - len, 1);
	while (j < i)
		do_wchar(s[j++], all);
	if (all->format[0] == '-')
		do_gap(all, ' ', all->width_predot - len, 1);
	return (all);
}