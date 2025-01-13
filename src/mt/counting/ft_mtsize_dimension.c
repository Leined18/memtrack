/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsize_dimension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:22:48 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 18:33:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	update_min_cord(t_mt *node, t_cords *min_cords)
{
	if (node->cords.x < min_cords->x)
		min_cords->x = node->cords.x;
	if (node->cords.y < min_cords->y)
		min_cords->y = node->cords.y;
	if (node->cords.z < min_cords->z)
		min_cords->z = node->cords.z;
}

static void	update_max_cord(t_mt *node, t_cords *max_cords)
{
	if (node->cords.x > max_cords->x)
		max_cords->x = node->cords.x;
	if (node->cords.y > max_cords->y)
		max_cords->y = node->cords.y;
	if (node->cords.z > max_cords->z)
		max_cords->z = node->cords.z;
}

static void	traverse_and_update(t_mt *node, t_cords *cords,
		void (*update_func)(t_mt *, t_cords *))
{
	if (!node || node->ptr_aux == NODE_VISITED)
		return ;
	node->ptr_aux = NODE_VISITED; // Marca el nodo como visitado
	update_func(node, cords);
	for (int i = 0; i < MAX_DIRECTIONS; i++)
	{
		if (node->vect[i])
			traverse_and_update(node->vect[i], cords, update_func);
	}
	node->ptr_aux = NULL; // Restablece al salir
}

int	ft_mtsize_dimension(t_mt *node, char dimension, char min_max)
{
	t_cords min_cords = {INT_MAX, INT_MAX, INT_MAX};
	t_cords max_cords = {INT_MIN, INT_MIN, INT_MIN};

	if (!node)
		return (0);

	if (min_max == '-')
		traverse_and_update(node, &min_cords, update_min_cord);
	else
		traverse_and_update(node, &max_cords, update_max_cord);

	if (dimension == 'x')
		return (min_max == '-' ? min_cords.x : max_cords.x);
	else if (dimension == 'y')
		return (min_max == '-' ? min_cords.y : max_cords.y);
	else if (dimension == 'z')
		return (min_max == '-' ? min_cords.z : max_cords.z);
	else
		return (0); // Dimensión no válida
}
