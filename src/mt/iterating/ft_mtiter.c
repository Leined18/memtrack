/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:12:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:59:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * traverse_node - Valida y recorre un nodo si no ha sido visitado.
 * @node: Nodo a validar y recorrer.
 * @param: Parámetro adicional para pasar a la función aplicada.
 * @func: Función a aplicar en el nodo.
 */

static void	traverse_node(t_mt *node, void *param, void (*func)(t_mt *, void *))
{
	if (node && !node->ptr_aux)
		ft_mtiter(node, param, func);
}

/**
 * ft_mtiter - Aplica una función a cada nodo de la estructura `t_mt`.
 * @lst: Nodo inicial para el recorrido.
 * @param: Parámetro adicional que se pasa a la función `func`.
 * @func: Función que se aplica a cada nodo visitado.
 */

void	ft_mtiter(t_mt *lst, void *param, void (*func)(t_mt *, void *))
{
	if (!lst || !func || lst->ptr_aux)
		return ;
	lst->ptr_aux = NULL;         // Restablece al entrar
	lst->ptr_aux = NODE_VISITED; // Marca el nodo como visitado
	traverse_node(lst->vect.right, param, func);
	traverse_node(lst->vect.left, param, func);
	traverse_node(lst->vect.up, param, func);
	traverse_node(lst->vect.down, param, func);
	lst->ptr_aux = NULL; // Restablece al salir
	func(lst, param);    // Aplica la función al nodo actual
}