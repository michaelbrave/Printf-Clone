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
# include "libft/libft.h"
# include <wchar.h>

/*
** Color Definitions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

/*
** Globals - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

/*
** Union is used to variable digit types
*/

// use an enum to set size of ll, j, z, LD etc
enum	e_flags {
	plus = 1 << 0,
	minus = 1 << 1,
	zero = 1 << 2,
	hash = 1 << 3,
	space = 1 << 4,
	neg = 1 << 7
};

enum	e_numlength {
	hh = sizeof(char),
	h = sizeof(short),
	l = sizeof(long),
	ll = sizeof(long long),
	j = sizeof(intmax_t),
	z = sizeof(size_t),
	t = sizeof(size_t),
	LD = sizeof(long double)
};

//currently not used
typedef union			u_digit
{
	void				*vdigit;
	double				flt;
	long double			ld;
}						t_digit;

/*
** -- An Explanation of the Struct - s_all/t_all --
** string: main body of text
** copy: copy of main element
** copy2:
** args: Arguments
** size: number of printed characters / return value
** i: Position in string
** flag_table: The letter portion of print, tells us how to cast it
** 		conversion specifiers "scSCdDiuUoOxXbp%"
** format_table: The sign portion of printf, tells us how to modify
** 		flags "-+ 0#"
** arg_table: dealing with integer conversion/length modifers
** 		"lhjz" l = long int, h = short int, j = intmax_t, z = size_t
** other length modifiers were not needed for this assignment
*/

typedef struct s_all
{
	char 	*string;
	char	*copy;
	char	*copy2;
	va_list	args;
	char	size;
	size_t	i;
	char	*flag_table;
	char	*format_table;
	char	*arg_table;
	char	flag;
	char	format[6];
	char	arg[2];
	long	precision_afterdot;
	long	width_predot;
}               t_all;

/*
** Printf Main Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/
int		ft_printf(const char *fmt, ...);
t_all	*initialize(char *fmt);
t_all	*reinitialize(t_all *all);

/*
** Parsing Functions
*/
int		parser(t_all *all);
int		mechanics(t_all *all);
t_all   *switch_do(t_all *all);
t_all   *parse_format(t_all *all);
t_all   *parse_width(t_all *all);
t_all	*parse_precision(t_all *all);
t_all	*parse_arg(t_all *all);
t_all	*parse_flags(t_all *all);

/*
** Flag Functions - do_functions - - - - - - - - - - - - - - - - - - - - - - - - - -
*/
t_all 	*do_d(t_all *all);
t_all 	*do_c(t_all *all);
t_all	*do_ws(t_all *all);
t_all	*do_s(t_all *all);
t_all	*do_u(t_all *all);
t_all	*do_x(t_all *all);
t_all	*do_o(t_all *all);
t_all	*do_p(t_all *all);
t_all	*do_other(t_all *all);
void	do_wchar(wint_t c, t_all *all);

/*
** Number Conversion Functions - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

/*
** Data Retrieval Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

/*
** Data Fomatting Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/


#endif