/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfilter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 12:03:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	traverse_node(t_mt *node, void *param, int (*predicate)(t_mt *,
			void *), t_mt **result)
{
	if (node && !node->ptr_aux)
		ft_mtfilter(node, param, predicate, result);
}

/**
 * ft_mtfilter - Filtra nodos de la estructura y los añade a una lista enlazada.
 * @lst: Nodo inicial para el recorrido.
 * @param: Parámetro adicional que se pasa a la función `predicate`.
 * @predicate: Función que determina si un nodo cumple con la condición.
 * @result: Puntero a la lista enlazada donde se agregarán los nodos filtrados.
 * usa ft_mtdup para duplicar los nodos que cumplan con la condición
 */

void	ft_mtfilter(t_mt *lst, void *param, int (*predicate)(t_mt *, void *),
		t_mt **result)
{
	if (!lst || !predicate || lst->ptr_aux)
		return ;
	lst->ptr_aux = NULL;         // Restablece al entrar
	lst->ptr_aux = NODE_VISITED; // Marca el nodo como visitado
	// Si el nodo cumple con la condición,
	if (predicate(lst, param))
		ft_mtadd_back(result, ft_mtdup(lst));
	// Recorre los nodos relacionados
	traverse_node(lst->right, param, predicate, result);
	traverse_node(lst->left, param, predicate, result);
	traverse_node(lst->parent, param, predicate, result);
	traverse_node(lst->children, param, predicate, result);
	lst->ptr_aux = NULL; // Restablece al salir
}
