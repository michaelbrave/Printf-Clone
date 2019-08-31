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

/*
** Color Definitions
*/

/*
** Globals
*/

//union goes here


/*
** -- An Explanation of the Struct - s_all/t_all --
** String: main body of text
** Copy: copy of main element
** Args: Arguments
** Size: number of printed characters / return value
** I: Position in string
** Specifier_Table: The letter portion of print, tells us how to cast it
** Converter_Table: The sign portion of printf, tells us how to modify
** Argument_Table: 
*/

typedef struct s_all
{
	char 	*string;
	char	*copy;
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
** Printf Main Functions
*/
int		ft_printf(const char *fmt, ...);
t_all	*initialize(char *fmt);
t_all	*reinitialize(t_all *all);

/*
** Parsing Functions
*/
int	parser(t_all *all);
int mechanics(t_all *all);

/*
** Flag Functions
*/

/*
** Number Conversion Functions
*/

/*
** Data Retrieval Functions
*/

/*
** Data Fomatting Functions
*/


#endif


/*
	
	int 	hash_alt;
    int 	dash_left;
    int 	plus_sign;
    int 	space_nosign;
    int 	zero_nopad;
 */