/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcount_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:51:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 12:09:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtcount_node_type
 * Cuenta los nodos de un tipo específico en un árbol/lista.
 * @node: Nodo raíz o inicio de la lista de nodos a procesar.
 * @type: Tipo de nodo que se desea contar.
 * Return: Número de nodos del tipo especificado.
 */

static int	match_node_type(t_mt *node, void *type)
{
	if (node->values.node_type == *(int *)type)
		return (1);
	return (0);
}

static int	match_data_type(t_mt *node, void *type)
{
	if (node->values.data_type == *(int *)type)
		return (1);
	return (0);
}

int	ft_mtcount_data_type(t_mt *node, t_data_type type)
{
	if (!node)
		return (0);
	return (ft_mtfold(node, &type, match_data_type));
}

int ft_mtcount_node_type(t_mt *node, t_node_type type)
{
	if (!node)
		return (0);
	return (ft_mtfold(node, &type, match_node_type));
}
