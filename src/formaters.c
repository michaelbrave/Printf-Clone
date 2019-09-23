/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:00:52 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/22 17:00:54 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char   *format_master(t_all *all, char *str)
{
all->altdone = 0;
all->signdone = 0;
if (all->precision == 0 && str[0] == '0' && str[1] == '\0' && all->precactiv == 1 && all->str != NULL) // hopefully correct?
	str[0] = '\0';
if (all->precision != 0)
	str = format_precision(all, str);
if (all->width != 0) // is there width to padd?
	str = format_width(all, str);
if (all->alt == '#' && all->altdone == 0) // do I need to do alt form?
	str = format_alt(all, str);
if (all->spec == 'd' || all->spec == 'i' || all->spec == 'o' || all->spec == 'x')
{
	if ((all->sign == '+' || all->sign == ' ' || all->neg == 1) && (all->signdone == 0)) // do I need to add a sign, or a space?
		str = format_sign(all, str);
}
return(str);
}

char *format_precision(t_all *all, char *str)
{
	int len;
	int i;
	char *tmp;

	tmp = NULL;
	i = 0;
	len = ft_strlen(str);
	if (len > all->precision && !(NUMBER)) //make it smaller
	{
		tmp = ft_strnew(all->precision);
        while(i < all->precision)
            {
                tmp[i] = str[i];
                i++;
            }
			tmp[i + 1] = '\0';
            str = tmp;
	}
	else if (len < all->precision) // make it longer
		{
			tmp = ft_strnew(all->precision - len);
			precision_padding(all, tmp, all->precision - len);
			str = ft_strjoin(tmp, str);
		}
	free(tmp);

return(str);
}

char *format_width(t_all *all, char *str)
{
	int len;
	char *tmp;

	tmp = NULL;
	len = ft_strlen(str);
	if (all->neg == 1 || all->sign == '+' || all->sign == ' ')
		len = len + 1;
	if (all->alt == '#' && (all->spec == 'x' || all->spec == 'X'))
		len = len + 2;
	if (all->alt == '#' && all->spec == 'o')
		len = len + 1;
	if (len < all->width) //make it longer or do nothing
	{
		tmp = ft_strnew(all->width - len);
		width_padding(all, tmp, all->width - len);
		if (all->alt == '#' && (all->spec == 'x' || all->spec == 'X' || all->spec == 'o') && all->padfill != '0')
			str = format_alt(all, str);
		if ((all->sign == '+' || all->sign == ' ' || all->neg == 1) && (all->spec == 'd' && all->padfill != '0'))
			str = format_sign(all, str);
		if (all->align == '-')
			str = ft_strjoin(str, tmp);
		else
			str = ft_strjoin(tmp, str);
	}
	free(tmp);

return(str);
}

char *format_alt(t_all *all, char *str)
{
all->altdone = 1;
if (str[0] == '0' && str[1] == '\0')
	return(str);
else if ((all->spec == 'x' || all->spec == 'X') && str[0] != '\0')
    str = ft_strjoin("0x", str);
else if (all->spec == 'o')
{
	if (all->width == 0)
		str = ft_strjoin("0", str); //wrong?
	else if (all->precision == 0)
		str = ft_strjoin("0", str); //wrong?
}
else if (all->spec == 'f')
	str = ft_strjoin(str, "."); //needs to make it always contain a decimal point, probably wrong

return(str);
}

char *format_sign(t_all *all, char *str)
{
	char *tmp;

	tmp = ft_strnew(2);
	tmp[0] = '0';
	tmp[1] = '\0';
	all->signdone = 1;
	//if (str[0] == '-')
	//	return(str);
	if (all->neg == 1)
		tmp[0] = '-';
	else if (all->sign == '+' && ft_atoi(str) >= 0)
		tmp[0] = '+';
	else if (all->sign == ' ' && ft_atoi(str) >= 0)
		tmp[0] = ' ';
	str = ft_strjoin(tmp, str);

	free(tmp);
return(str);
}
