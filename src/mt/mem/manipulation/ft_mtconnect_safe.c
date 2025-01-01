/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconnect_safe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:09:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 12:37:48 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconnect_safe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:20:53 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 02:11:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	ft_connect_node(t_mt *node, t_mt *new_node, int direction)
{
	int	opposite;

	opposite = (direction + 1) % 6;
	if (node->vect[direction])
		ft_disconnect_node(node, direction);
	node->vect[direction] = new_node;
	new_node->vect[opposite] = node;
}

static void	ft_reconnect_opposites(t_mt *node, t_mt *new_node, int direction)
{
	int		opposite;
	t_mt	*neighbor;
	t_mt	*opposite_node;

	opposite = (direction + 1) % 6;
	neighbor = node->vect[direction];
	opposite_node = node->vect[opposite];
	if (neighbor && opposite_node)
		ft_connect_nodes(opposite_node, direction, neighbor, opposite);
	else if (neighbor)
		ft_reconnect_single(node, neighbor, opposite, direction);
	else if (opposite_node)
		ft_reconnect_single(node, opposite_node, direction, opposite);
	ft_connect_node(node, new_node, direction);
}

t_mt	*ft_mtconnect_safe(t_mt **ref, t_mt *node, t_mt *new_node,
		int direction)
{
	if (!ref || !*ref || !node || !new_node)
		return (NULL);
	// Si el nodo es la referencia base, actualizamos la referencia
	ft_mtupdate_ref(ref, node);
	ft_reconnect_opposites(node, new_node, direction);
	return (new_node);
}
