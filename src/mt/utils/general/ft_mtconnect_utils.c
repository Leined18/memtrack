/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconnect_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 12:37:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_connect_nodes(t_mt *node1, int direction1, t_mt *node2,
		int direction2)
{
	if (node1 && node2)
	{
		node1->vect[direction1] = node2;
		node2->vect[direction2] = node1;
	}
}

void	ft_disconnect_node(t_mt *node, int direction)
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

void	ft_reconnect_single(t_mt *node, t_mt *single_node, int direction,
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
