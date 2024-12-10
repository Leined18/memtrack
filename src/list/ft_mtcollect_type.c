/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcollect_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:58:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/10 12:27:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtcollect_types - Recolecta nodos de un tipo específico en un árbol/lista.
 * @mt: Nodo raíz o inicio de la lista de nodos a procesar.
 * @type: Tipo de dato que se desea recolectar.
 *
 * Return: Lista enlazada de nodos recolectados.
 */

// no usar por ahora type branch

t_mt	*ft_mtcollect_node_type_mt(t_mt *mt, t_node_type type)
{
	t_mt	*collected;
	t_mt	*sub;

	if (!mt)
		return (NULL);
	collected = NULL;
	sub = NULL;
	if (mt->values.node_type == (int)type)
	{
		sub = ft_mtdup(mt);
		ft_mtpush_back(&sub, &collected);
	}
	if (mt->children)
	{
		sub = ft_mtcollect_node_type_list(mt->children, type);
		ft_mtmigrate_back(&sub, &collected);
	}
	if (collected)
		ft_mtset_to_free(collected, 0);
	return (collected);
}

t_mt	*ft_mtcollect_data_type_mt(t_mt *mt, t_data_type type)
{
	t_mt	*collected;
	t_mt	*sub;

	if (!mt)
		return (NULL);
	collected = NULL;
	sub = NULL;
	if (mt->values.data_type == (int)type)
	{
		sub = ft_mtdup(mt);
		ft_mtpush_back(&sub, &collected);
	}
	if (mt->children)
	{
		sub = ft_mtcollect_data_type_list(mt->children, type);
		ft_mtmigrate_back(&sub, &collected);
	}
	if (collected)
		ft_mtset_to_free(collected, 0);
	return (collected);
}

t_mt	*ft_mtcollect_data_type_list(t_mt *mt, t_data_type type)
{
	t_mt	*collected;
	t_mt	*current;
	t_mt	*sub;

	if (!mt)
		return (NULL);
	collected = NULL;
	current = mt;
	while (current)
	{
		sub = ft_mtcollect_data_type_mt(current, type);
		ft_mtmigrate_back(&sub, &collected);
		current = current->right;
	}
	ft_mtset_to_free(collected, 0);
	return (collected);
}

t_mt	*ft_mtcollect_node_type_list(t_mt *mt, t_node_type type)
{
	t_mt	*collected;
	t_mt	*current;
	t_mt	*sub;

	if (!mt)
		return (NULL);
	collected = NULL;
	current = mt;
	while (current)
	{
		sub = ft_mtcollect_node_type_mt(current, type);
		ft_mtmigrate_back(&sub, &collected);
		current = current->right;
	}
	ft_mtset_to_free(collected, 0);
	return (collected);
}
