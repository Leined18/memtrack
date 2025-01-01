/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdisconnect_safe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:20:53 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 12:36:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"


static void	ft_reconnect_opposites(t_mt *node, int direction)
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
}

t_mt	*ft_mtdisconnect_safe(t_mt **ref, t_mt *node)
{
	int	i;

	if (!ref || !*ref || !node)
		return (NULL);
	i = 0;
	// Si el nodo es la referencia base, actualizamos la referencia
	ft_mtupdate_ref(ref, node);
	while (i < MAX_DIRECTIONS)
	{
		if (node->vect[i])
		{
			ft_reconnect_opposites(node, i);
			ft_disconnect_node(node, i);
		}
		i++;
	}
	return (node);
}
