/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:25:26 by mbrave            #+#    #+#             */
/*   Updated: 2019/05/28 14:32:50 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../src/libft/libft.h"
# include <wchar.h> //make sure using
#include <limits.h> //make sure actually using

# define SPEC(x) (all->str[all->i + (x)])
# define STR(x) (all->str[(x)])
# define NUMBER (all->spec == 'X' || all->spec == 'x' || all->spec == 'd' || \
all->spec == 'i'|| all->spec == 'o' || all->spec == 'u')

typedef struct s_all
{
	va_list args;
	char	*str;
	char	*toprint;
	size_t	size;
	size_t	i;
	size_t  here_percent;
	size_t  here_spec;
	char	spec;
	int		length;
	long	width;
	long	precision;
	char	padfill;
	char	sign;
	char	alt;
	char	align;
	int		neg;
	int		altdone;
	int		signdone;
	int		precactiv;
}			t_all;

// Main Files
int		ft_printf(const char *format, ...);

// Intializers
t_all	*initialize(char *format);
void	make_queue(t_all *all);
char	*width_padding(t_all *all, char *tmp, int len);
char	*precision_padding(t_all *all, char *tmp, int len);

// Parsers
void	print_or_parse(t_all *all);
void	find_spec(t_all *all);
void	finder_main(t_all *all);
void	find_width(t_all *all);
void	find_precision(t_all *all);
void	find_length(t_all *all);

// Converting
void	switch_do(t_all *all);
int		do_d(t_all *all);
int		do_f(t_all *all);
int		do_c(t_all *all);
int		do_s(t_all *all);
int		do_u(t_all *all);
int		do_x(t_all *all);
int		do_o(t_all *all);
int		do_p(t_all *all);
int     do_percent(t_all *all);

// Length
char	*length(t_all *all, char *str, int base);
char	*make_int(t_all *all, char *str, void *holder, int base);
char	*make_short(t_all *all, char *str, void *holder, int base);
char	*make_char(t_all *all, char *str, void *holder, int base);
char	*make_long(t_all *all, char *str, void *holder, int base);
char	*make_long_long(t_all *all, char *str, void *holder, int base);
char	*make_long_double(t_all *all, char *str, void *holder, int base);
char	*make_unsigned(t_all *all, char *str, void *holder, int base);
char 	*make_unsigned_long(t_all *all, char *str, void *holder, int base);
char	*check_negative(t_all *all, char * str);

// Formatting
char	*format_master(t_all *all, char *str);
char	*format_precision(t_all *all, char *str);
char	*format_width(t_all *all, char *str);
char	*format_alt(t_all *all, char *str);
char	*format_sign(t_all *all, char *str);

// Printing
void	printprint(t_all *all);

// Freeing
void	cleanclean(t_all *all);

#endif