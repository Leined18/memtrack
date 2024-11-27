/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcollect_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:58:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 20:38:41 by danpalac         ###   ########.fr       */
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
t_mt	*ft_mtcollect_types(t_mt *mt, t_data_type type)
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
		if (current->type == type)
			ft_mtadd_back(&collected, ft_mtnew(current->key, current->data,
					type));
		if (current->type == BRANCH && current->data)
		{
			sub = ft_mtcollect_types((t_mt *)current->data, type);
			ft_mtmigrate_back(&sub, &collected);
		}
		current = current->next;
	}
	ft_mtset_to_free(collected, 0);
	return (collected);
}
