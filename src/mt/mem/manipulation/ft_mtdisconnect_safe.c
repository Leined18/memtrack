/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdisconnect_safe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:20:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:27:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	ft_mtupdate_ref(t_mt **ref, t_mt *node)
{
	if (*ref == node)
	{
		// Asignamos un nuevo nodo base si es posible
		if (node->vect.right)
			*ref = node->vect.right;
		else if (node->vect.left)
			*ref = node->vect.left;
		else if (node->vect.up)
			*ref = node->vect.up;
		else if (node->vect.down)
			*ref = node->vect.down;
		else
			*ref = NULL; // No hay nodos restantes
	}
}
t_mt	*ft_mtdisconnect_horizontal(t_mt *node)
{
	if (!node)
		return (NULL);
	if (node->vect.left && node->vect.left->vect.right == node)
		ft_mtconnect_right(node->vect.left, node->vect.right);
	if (node->vect.right && node->vect.right->vect.left == node)
		ft_mtconnect_left(node->vect.right, node->vect.left);
	node->vect.left = NULL;
	node->vect.right = NULL;
	return (node);
}

t_mt	*ft_mtdisconnect_vertical(t_mt *node)
{
	if (!node)
		return (NULL);
	if (node->vect.up && node->vect.down)
		ft_mtconnect_down(node->vect.up, node->vect.down);
	if (node->vect.down && node->vect.up)
		ft_mtconnect_up(node->vect.down, node->vect.up);
	if (!node->vect.up && node->vect.down)
	{
		if (node->vect.right)
			ft_mtconnect_left(node->vect.right, node->vect.down);
		if (node->vect.left)
			ft_mtconnect_right(node->vect.left, node->vect.down);
		ft_mtdisconnect_down(node);
	}
	node->vect.up = NULL;
	node->vect.down = NULL;
	return (node);
}

t_mt	*ft_mtdisconnect_safe(t_mt **ref, t_mt *node)
{
	if (!ref || !*ref || !node)
		return (NULL);
	// Si el nodo es la referencia base, actualizamos la referencia
	ft_mtupdate_ref(ref, node);
	ft_mtdisconnect_vertical(node);
	// Reconectar nodos adyacentes horizontalmente
	ft_mtdisconnect_horizontal(node);
	// Reconectar nodos adyacentes verticalmente
	return (node);
}
