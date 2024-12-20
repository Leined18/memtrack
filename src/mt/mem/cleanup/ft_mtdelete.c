/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdelete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 08:32:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtdelete(t_mt **mt)
{
	if (!mt || !*mt)
		return ;
	if ((*mt)->data)
		ft_mtdel_by_type(&(*mt)->data, (*mt)->values.data_type);
	if ((*mt)->vect.down)
		ft_mtclear(&(*mt)->vect.down);
	if ((*mt)->key)
		free((*mt)->key);
	free((*mt));
	(*mt) = NULL;
}
