/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:12:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:53 by danpalac         ###   ########.fr       */
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
	traverse_node(lst->vect[RIGHT], param, func);
	traverse_node(lst->vect[LEFT], param, func);
	traverse_node(lst->vect[UP], param, func);
	traverse_node(lst->vect[DOWN], param, func);
	traverse_node(lst->vect[BACK], param, func);
	traverse_node(lst->vect[FRONT], param, func);
	traverse_node(lst->aux, param, func);
	lst->ptr_aux = NULL; // Restablece al salir
	func(lst, param);    // Aplica la función al nodo actual
}