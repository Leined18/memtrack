/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdisconnect_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:14:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:27:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtdisconnect_left(t_mt *node)
{
	t_mt	*tmp;

	if (!node)
		return (NULL);
	tmp = node->vect.left;
	node->vect.left = NULL;
	if (tmp)
		tmp->vect.right = NULL;
	return (tmp);
}

t_mt	*ft_mtdisconnect_right(t_mt *node)
{
	t_mt	*tmp;

	if (!node)
		return (NULL);
	tmp = node->vect.right;
	node->vect.right = NULL;
	if (tmp)
		tmp->vect.left = NULL;
	return (tmp);
}

t_mt	*ft_mtdisconnect_up(t_mt *node)
{
	t_mt	*tmp;

	if (!node)
		return (NULL);
	tmp = node->vect.up;
	node->vect.up = NULL;
	if (tmp)
		tmp->vect.down = NULL;
	return (tmp);
}

t_mt	*ft_mtdisconnect_down(t_mt *node)
{
	t_mt *tmp;

	if (!node)
		return (NULL);
	tmp = node->vect.down;
	node->vect.down = NULL;
	if (tmp)
		tmp->vect.up = NULL;
	return (tmp);
}