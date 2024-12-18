/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:47 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 13:16:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mthash_remove - Elimina un nodo de la tabla hash basado en la clave.
 * @ht: Tabla hash.
 * @key: Clave del nodo a eliminar.
 *
 * Retorna 0 si tuvo éxito, -1 si falló (clave no encontrada).
 */

// falta actualizar para eliminar en cualquier parte de la lista
// elimina un nodo de la tabla hash basado en la clave

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
	t_mt	*tmp;

	if (!node)
		return (NULL);
	tmp = node->vect.down;
	node->vect.down = NULL;
	if (tmp)
		tmp->vect.up = NULL;
	return (tmp);
}

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

// DFS, BFS, A* o IDA* (Algoritmos de Búsqueda).

int	ft_mthash_remove_node(t_hash_table *ht, const char *key)
{
	t_mt	*current;
	t_mt	*tmp;
	int		index;

	if (!ht || !key)
		return (-1);
	index = ft_mthash_get_index(ht, key);
	if (index == -1)
		return (-1);
	current = ft_mtsearch_key(ht->buckets[index], key);
	if (!current)
		return (-1);
	tmp = current;
	ft_mtconnect_left(current->vect.right, current->vect.left);
	ft_mtconnect_right(current->vect.left, current->vect.right);
	tmp->vect.left = NULL;
	tmp->vect.right = NULL;
	ft_mtfree(tmp);
	return (1); // si se elimina correctamente
}
