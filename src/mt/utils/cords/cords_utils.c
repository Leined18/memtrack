/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:58:46 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 13:29:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_cords	ft_cords(int x, int y, int z)
{
	t_cords	cords;

	cords.x = x;
	cords.y = y;
	cords.z = z;
	return (cords);
}

t_cords	ft_cords_diff(t_cords cords, int x, int y, int z)
{
	cords.x += x;
	cords.y += y;
	cords.z += z;
	return (cords);
}

static void	update_cords_recursive(t_mt *node, t_cords cords)
{
	t_cords	new_cords;

	for (int i = 0; i < MAX_DIRECTIONS; i++)
	{
		if (node->vect[i])
		{
			new_cords = cords;
			if (i == 0)
				update_cords(node->vect[i], ft_cords_diff(new_cords, 1, 0, 0));
			else if (i == 1)
				update_cords(node->vect[i], ft_cords_diff(new_cords, -1, 0, 0));
			else if (i == 2)
				update_cords(node->vect[i], ft_cords_diff(new_cords, 0, 1, 0));
			else if (i == 3)
				update_cords(node->vect[i], ft_cords_diff(new_cords, 0, -1, 0));
			else if (i == 4)
				update_cords(node->vect[i], ft_cords_diff(new_cords, 0, 0, 1));
			else if (i == 5)
				update_cords(node->vect[i], ft_cords_diff(new_cords, 0, 0, -1));
		}
	}
}

void	update_cords(t_mt *node, t_cords cords)
{
	if (!node || node->ptr_aux)
		return ;
	node->cords = cords;
	node->ptr_aux = NODE_VISITED;
	update_cords_recursive(node, cords);
	node->ptr_aux = NULL;
}
