/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 03:56:18 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/26 04:16:58 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision_helper(t_all *all, char *tmp, char *str, int len)
{
	char	*ret;

	tmp = ft_strnew(all->precision - len);
	precision_padding(all, tmp, all->precision - len);
	ret = ft_strjoin(tmp, str);
	free(tmp);
	free(str);
	return (ret);
}

char	*format_precision(t_all *all, char *str)
{
	int		len;
	char	*tmp;

	tmp = NULL;
	len = ft_strlen(str);
	if (*str == '\0')
		return (str);
	if (all->zeroprecision == '0' && all->precision == 0 && ZERO)
		str[0] = '\0';
	else if (len > all->precision && !(NUMBER) && NOTP)
	{
		tmp = ft_strsub(str, 0, all->precision);
		free(str);
		str = tmp;
	}
	else if (len < all->precision && NOCHAR && *str != '\0')
		str = precision_helper(all, tmp, str, len);
	return (str);
}

char	*width_helper(t_all *all, char *tmp, char *str, int len)
{
	char	*ret;

	tmp = ft_strnew(all->width - len);
	width_padding(all, tmp, all->width - len);
	if (all->alt == '#' && SPECIAL && all->padfill != '0')
		str = format_alt(all, str);
	if (SIGN && (all->spec == 'd' && all->padfill != '0'))
		str = format_sign(all, str);
	ret = (all->align == '-') ? ft_strjoin(str, tmp) : ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	str = ret;
	return (str);
}

char	*format_width(t_all *all, char *str)
{
	int		len;
	char	*tmp;

	tmp = NULL;
	len = ft_strlen(str);
	if (len == 0 && all->spec == 'c')
		len = 1;
	if (all->neg == 1 || all->sign == '+' || all->sign == ' ')
		len = len + 1;
	if (all->alt == '#' && (all->spec == 'x' || all->spec == 'X'))
		len = len + 2;
	if (all->alt == '#' && all->spec == 'o')
		len = len + 1;
	if (len < all->width)
		str = width_helper(all, tmp, str, len);
	return (str);
}
