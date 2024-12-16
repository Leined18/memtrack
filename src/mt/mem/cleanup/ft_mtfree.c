/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 13:22:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtfree(t_mt *mt)
{
	ft_mtdel_by_type(&mt->data, mt->values.data_type);
	mt->data = NULL;
	mt->ptr_aux = "freed";
	if (mt->children)
		ft_mtclear(&mt->children);
	free(mt->key);
	free(mt);
}
