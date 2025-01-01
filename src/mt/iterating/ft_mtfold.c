/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfold.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:19:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtfold - Recorre la estructura t_mt y aplica una función acumulativa.
 * @lst: Nodo inicial para comenzar el recorrido.
 * @param: Parámetro adicional que se pasa a la función acumulativa.
 * @func: Función que se aplica a cada nodo; debe retornar un entero.
 *

		* Return: La suma de los resultados devueltos por func en todos los
 nodos visitados.
 */

static int	traverse_node(t_mt *node, void *param, int (*func)(t_mt *, void *))
{
	if (node && !node->ptr_aux)
		return (ft_mtfold(node, param, func));
	return (0);
}

int	ft_mtfold(t_mt *lst, void *param, int (*func)(t_mt *, void *))
{
	int	result;

	if (!lst || !func || lst->ptr_aux)
		return (0);
	result = 0;
	lst->ptr_aux = NODE_VISITED;
	result += traverse_node(lst->vect[RIGHT], param, func);
	result += traverse_node(lst->vect[LEFT], param, func);
	result += traverse_node(lst->vect[UP], param, func);
	result += traverse_node(lst->vect[DOWN], param, func);
	result += traverse_node(lst->vect[BACK], param, func);
	result += traverse_node(lst->vect[FRONT], param, func);
	result += traverse_node(lst->aux, param, func);
	lst->ptr_aux = NULL;
	result += func(lst, param);
	return (result);
}
