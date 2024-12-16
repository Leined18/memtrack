/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcollect_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:58:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 15:16:21 by danpalac         ###   ########.fr       */
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

t_mt	*ft_mtcollect_node_type(t_mt *mt, t_node_type type)
{
	t_mt	*collected;

	if (!mt || mt->ptr_aux)
		return (NULL);
	collected = NULL;
	if (mt->values.node_type == (int)type)
		ft_mtadd_back(&collected, ft_mtdup(mt));
	mt->ptr_aux = "used";
	if (mt->right)
		ft_mtadd_back(&collected, ft_mtcollect_node_type(mt->right, type));
	if (mt->left)
		ft_mtadd_back(&collected, ft_mtcollect_node_type(mt->left, type));
	if (mt->parent)
		ft_mtadd_back(&collected, ft_mtcollect_node_type(mt->parent, type));
	if (mt->children)
		ft_mtadd_back(&collected, ft_mtcollect_node_type(mt->children, type));
	mt->ptr_aux = NULL;
	return (collected);
}

t_mt	*ft_mtcollect_data_type(t_mt *mt, t_data_type type)
{
	t_mt *collected;

	if (!mt || mt->ptr_aux)
		return (NULL);
	collected = NULL;
	if (mt->values.data_type == (int)type)
		ft_mtadd_back(&collected, ft_mtdup(mt));
	mt->ptr_aux = "used";
	if (mt->right)
		ft_mtadd_back(&collected, ft_mtcollect_data_type(mt->right, type));
	if (mt->left)
		ft_mtadd_back(&collected, ft_mtcollect_data_type(mt->left, type));
	if (mt->parent)
		ft_mtadd_back(&collected, ft_mtcollect_data_type(mt->parent, type));
	if (mt->children)
		ft_mtadd_back(&collected, ft_mtcollect_data_type(mt->children, type));
	mt->ptr_aux = NULL;
	return (collected);
}