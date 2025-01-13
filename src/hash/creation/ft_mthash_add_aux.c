/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_add_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:05:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/05 12:35:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// añade un hijo a un nodo de la tabla hash y si no encuentra al padre crea un nuevo nodo padre
// y añade al hijo

int	ft_mthash_add_aux(t_hash_table *ht, const char *key, t_mt *aux)
{
	t_mt	*parent;
	int		index;

	if (!ht || !key || !aux)
		return (0);
	parent = ft_mthash_find_node(ht, key);
	if (!parent)
	{
		index = ft_mthash(key, ht->bucket_count);
		parent = ft_mtnew(key, NULL, NONE);
		if (!parent)
			return (ft_mtdelete(&aux), 0);
		parent->values.node_type = BRANCH;
		ft_mtaddlast_right(&ht->buckets[index], parent);
		return (ft_mtaddlast_aux(parent, aux), 1);
	}
	return (ft_mtaddlast_aux(parent, aux), 1);
}

// si funciona
