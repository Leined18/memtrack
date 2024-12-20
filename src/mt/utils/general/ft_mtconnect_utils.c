/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconnect_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:27:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtconnect_left(t_mt *node, t_mt *left)
{
	if (!node)
		return (NULL);
	node->vect.left = left;
	if (left)
		left->vect.right = node;
	return (left);
}
t_mt	*ft_mtconnect_right(t_mt *node, t_mt *right)
{
	if (!node)
		return (NULL);
	node->vect.right = right;
	if (right)
		right->vect.left = node;
	return (right);
}

t_mt	*ft_mtconnect_up(t_mt *node, t_mt *up)
{
	if (!node)
		return (NULL);
	node->vect.up = up;
	if (up)
		up->vect.down = node;
	return (up);
}

t_mt	*ft_mtconnect_down(t_mt *node, t_mt *down)
{
	if (!node)
		return (NULL);
	node->vect.down = down;
	if (down)
		down->vect.up = node;
	return (down);
}