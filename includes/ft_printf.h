/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:25:26 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 21:50:08 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../src/libft/libft.h"
# include <wchar.h>
# include <limits.h>

# define SPEC(x)	(all->str[all->i + (x)])
# define STR(x)		(all->str[(x)])
# define NUMBER		(all->spec == 'X' || all->spec == 'x' || NUMBER2)
# define NUMBER2	(all->spec == 'o' || all->spec == 'u' || NUMBER3)
# define NUMBER3	(all->spec == 'i'|| all->spec == 'd')
# define PRE		(all->precactiv == 0)
# define PRE1		(all->precactiv == 1)
# define ZERO		(str[0] == '0' && str[1] == '\0')
# define SIGN		(all->sign == '+' || all->sign == ' ' || all->neg == 1)
# define NOCHAR		(all->spec != 's' && all->spec != 'c')
# define NOTP		(all->spec != '%' && all->spec != 'p')
# define SPECIAL	(all->spec == 'x' || all->spec == 'X' || all->spec == 'o')
# define LFLAG		(all->str[all->i] == 'h' || LFLAG2)
# define LFLAG2		(all->str[all->i] == 'l' || all->str[all->i] == 'L')

typedef struct		s_all
{
	va_list			args;
	char			*str;
	char			*toprint;
	size_t			size;
	size_t			retsize;
	size_t			i;
	size_t			here_percent;
	size_t			here_spec;
	char			spec;
	char			length[7];
	long			width;
	long			precision;
	char			zeroprecision;
	char			padfill;
	char			sign;
	char			alt;
	char			align;
	int				neg;
	int				altdone;
	int				signdone;
	int				precactiv;
}					t_all;

/*
** Main Files
*/
int					ft_printf(const char *format, ...);

/*
** Intializers
*/
t_all				initialize(char *format);
char				*width_padding(t_all *all, char *tmp, int len);
char				*precision_padding(t_all *all, char *tmp, int len);
void				length_reset(t_all *all);

/*
** Parsers
*/
void				print_or_parse(t_all *all);
void				find_spec(t_all *all, int i);
void				finder_main(t_all *all);
void				find_width(t_all *all);
void				find_precision(t_all *all, int j);
void				find_length(t_all *all);

/*
** Converting
*/
void				switch_do(t_all *all);
int					do_d(t_all *all);
int					do_f(t_all *all);
int					do_c(t_all *all);
int					do_s(t_all *all);
int					do_u(t_all *all);
int					do_x(t_all *all);
int					do_o(t_all *all);
int					do_p(t_all *all);
int					do_percent(t_all *all);

/*
** Length
*/
char				*length(t_all *all, char *str, int base);
char				*make_int(t_all *all, char *str, int base);
char				*make_short(t_all *all, char *str, int base);
char				*make_char(t_all *all, char *str, int base);
char				*make_long(t_all *all, char *str, int base);
char				*make_long_long(t_all *all, char *str, int base);
char				*check_negative(t_all *all, char *str);

/*
** Float Length & Stuff
*/
char				*make_long_double(t_all *a, char *s, long double h);
char				*float_length(t_all *all, char *str, long double holder);
char				*roundup(char *str);
char				*ft_itoa_float(t_all *all, double n);

/*
** Formatting
*/
char				*format_master(t_all *all, char *str);
char				*format_precision(t_all *all, char *str);
char				*format_width(t_all *all, char *str);
char				*format_alt(t_all *all, char *str);
char				*format_sign(t_all *all, char *str);
char				*format_p(t_all *all, char *str);

/*
** Printing
*/
void				printprint(t_all *all);
void				make_queue(t_all *all);
char				*ft_strjoin_len(char *s1, char *s2, int len);

/*
** Freeing
*/
void				cleanclean(t_all *all);

#endif
