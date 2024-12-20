/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 12:18:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static t_mt	*traverse_node(t_mt *node, void *param, int (*predicate)(t_mt *,
			void *))
{
	if (node && !node->ptr_aux)
		return (ft_mtsearch(node, param, predicate));
	return (NULL);
}

/**
 * ft_mtsearch
	- Busca un nodo en la estructura t_mt que cumpla con la condición.
 * @lst: Nodo inicial para comenzar la búsqueda.
 * @param: Parámetro adicional que se pasa a la función `predicate`.
 * @predicate: Función que determina si un nodo cumple con la condición.
 *
 * Return: El nodo que cumple con la condición, o NULL si no se encontró.
 */

static t_mt	*traverse_comprimed(t_mt *node, void *param,
		int (*predicate)(t_mt *, void *))
{
	t_mt	*found;

	found = NULL;
	if (node->vect.left && !found)
		found = traverse_node(node->vect.left, param, predicate);
	if (node->vect.right && !found)
		found = traverse_node(node->vect.right, param, predicate);
	if (node->vect.up && !found)
		found = traverse_node(node->vect.up, param, predicate);
	if (node->vect.down && !found)
		found = traverse_node(node->vect.down, param, predicate);
	if (node->aux && !found)
		found = traverse_node(node->aux, param, predicate);
	if (node->vect.back && !found)
		found = traverse_node(node->vect.back, param, predicate);
	if (node->vect.front && !found)
		found = traverse_node(node->vect.front, param, predicate);
	return (found);
}

t_mt	*ft_mtsearch(t_mt *lst, void *param, int (*predicate)(t_mt *, void *))
{
	t_mt	*found;

	if (!lst || !predicate || lst->ptr_aux)
		return (NULL);
	lst->ptr_aux = NODE_VISITED; // Marca el nodo como visitado
	// Si el nodo cumple la condición, retornarlo directamente
	if (predicate(lst, param))
	{
		lst->ptr_aux = NULL;
		return (lst);
	}
	found = traverse_comprimed(lst, param, predicate);
	lst->ptr_aux = NULL; // Restablece al salir
	return (found);      // Retorna el nodo encontrado, o NULL si no se encontró
}
