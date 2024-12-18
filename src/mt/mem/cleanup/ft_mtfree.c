/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 13:03:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtfree(t_mt *mt)
{
	ft_mtdel_by_type(&mt->data, mt->values.data_type);
	mt->data = NULL;
	mt->ptr_aux = "freed";
	if (mt->vect.down)
		ft_mtclear(&mt->vect.down);
	free(mt->key);
	free(mt);
}
