/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:53 by danpalac         ###   ########.fr       */
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
	if (node->vect[LEFT] && !found)
		found = traverse_node(node->vect[LEFT], param, predicate);
	if (node->vect[RIGHT] && !found)
		found = traverse_node(node->vect[RIGHT], param, predicate);
	if (node->vect[UP] && !found)
		found = traverse_node(node->vect[UP], param, predicate);
	if (node->vect[DOWN] && !found)
		found = traverse_node(node->vect[DOWN], param, predicate);
	if (node->aux && !found)
		found = traverse_node(node->aux, param, predicate);
	if (node->vect[BACK] && !found)
		found = traverse_node(node->vect[BACK], param, predicate);
	if (node->vect[FRONT] && !found)
		found = traverse_node(node->vect[FRONT], param, predicate);
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
	found = NULL;
	found = traverse_comprimed(lst, param, predicate);
	lst->ptr_aux = NULL; // Restablece al salir
	return (found);      // Retorna el nodo encontrado, o NULL si no se encontró
}
