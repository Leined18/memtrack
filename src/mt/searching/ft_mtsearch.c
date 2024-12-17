/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 11:55:20 by danpalac         ###   ########.fr       */
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
	// Buscar en los nodos adyacentes
	found = NULL;
	found = traverse_node(lst->right, param, predicate);
	if (!found)
		found = traverse_node(lst->left, param, predicate);
	if (!found)
		found = traverse_node(lst->parent, param, predicate);
	if (!found)
		found = traverse_node(lst->children, param, predicate);
	lst->ptr_aux = NULL; // Restablece al salir
	return (found);      // Retorna el nodo encontrado, o NULL si no se encontró
}
