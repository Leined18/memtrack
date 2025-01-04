/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:12:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/04 20:19:36 by danpalac         ###   ########.fr       */
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
	int	i;

	if (!node)
		return ;
	i = 0;
	while (i < MAX_DIRECTIONS)
	{
		if (node->vect[i] && node->vect[i]->ptr_aux != NODE_VISITED)
		{
			node->vect[i]->ptr_aux = NODE_VISITED;
			traverse_node(node->vect[i], param, func);
			node->vect[i]->ptr_aux = NULL;
			func(node->vect[i], param);
		}
		i++;
	}
}

/**
 * ft_mtiter - Aplica una función a cada nodo de la estructura `t_mt`.
 * @lst: Nodo inicial para el recorrido.
 * @param: Parámetro adicional que se pasa a la función `func`.
 * @func: Función que se aplica a cada nodo visitado.
 */

void	ft_mtiter(t_mt *lst, void *param, void (*func)(t_mt *, void *))
{
	if (!lst || !func)
		return ;
	lst->ptr_aux = NODE_VISITED;
	traverse_node(lst, param, func);
	lst->ptr_aux = NULL;
}
