/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtinsert_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:46 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 12:20:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_cmp_cords(t_mt *node, t_cords s_cords)
{
	if (!node)
		return (0);
	if (node->cords.x == s_cords.x && node->cords.y == s_cords.y
		&& node->cords.z == s_cords.z)
		return (1);
	return (0);
}

static int	match_cords(t_mt *node, void *cords)
{
	t_cords	*c;

	if (!node || !cords)
		return (0);
	c = (t_cords *)cords;
	if (ft_cmp_cords(node, *c))
		return (1);
	return (0);
}

// Inserts the element 'new_node' at the position 'pos' of the list.
void	ft_mtinsert_cord(t_mt **list, t_mt *new_node, t_cords cords)
{
	t_mt *node;
	if (!list || !new_node)
		return ;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	node = ft_mtsearch(*list, &cords, match_cords);
	if (!node)
		return ;
	
}
