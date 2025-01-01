/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdisconnect_safe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:20:53 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 02:11:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	ft_mtupdate_ref(t_mt **ref, t_mt *node)
{
	int	i;

	i = 0;
	if (*ref == node)
	{
		// Asignamos un nuevo nodo base si es posible
		while (i < 6)
		{
			if (node->vect[i])
			{
				*ref = node->vect[i];
				return ;
			}
			i++;
		}
		*ref = NULL; // No hay nodos restantes
	}
}

static void	ft_disconnect_node(t_mt *node, int direction)
{
	int		opposite;
	t_mt	*neighbor;

	opposite = (direction + 1) % 6;
	neighbor = node->vect[direction];
	if (neighbor)
	{
		if (neighbor->vect[opposite] == node)
			neighbor->vect[opposite] = NULL;
		if (neighbor->vect[(direction - 1) % 6] == node)
			neighbor->vect[(direction - 1) % 6] = NULL;
		node->vect[direction] = NULL;
	}
}

static void	ft_reconnect_single(t_mt *node, t_mt *single_node, int direction,
		int opposite)
{
	for (int i = 0; i < 6; i++)
	{
		if (i != direction && i != opposite && node->vect[i])
		{
			ft_connect_nodes(single_node, (direction + 1) % 6, node->vect[i], (i
					- 1) % 6);
			break ;
		}
	}
}

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
