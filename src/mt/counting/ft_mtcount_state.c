/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcount_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:08:55 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 12:10:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * match_state - Compara el estado del nodo con el estado pasado como parámetro.
 * @node: Nodo a comparar.
 * @state: Estado de nodo a comparar.
 * Return: 1 si el nodo es del estado pasado, 0 en caso contrario.
 */

static int match_state(t_mt *node, void *state)
{
	if (node->values.state == *(int *)state)
		return (1);
	return (0);
}

/**
 * ft_mtcount_state
 * Cuenta los nodos de un estado específico en un árbol/lista.
 * @node: Nodo raíz o inicio de la lista de nodos a procesar.
 * @state: Estado de nodo que se desea contar.
 * Return: Número de nodos del estado especificado.
 * usa ft_mtfold para contar los nodos de un estado específico
 */

int	ft_mtcount_state(t_mt *node, int state)
{
	if (!node)
		return (0);
	return (ft_mtfold(node, &state, match_state));
}
