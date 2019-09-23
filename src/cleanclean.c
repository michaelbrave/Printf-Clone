/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanclean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:10:42 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/22 14:10:44 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//this frees free(all things needing freeing

void	cleanclean(t_all *all)
{
	free(all->args);
	//free(all->str);
	//free(all->toprint);
}
