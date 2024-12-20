/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_add_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:05:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:41:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// añade un hijo a un nodo de la tabla hash y si no encuentra al padre crea un nuevo nodo padre
// y añade al hijo

int	ft_mthash_add_child(t_hash_table *ht, const char *key, t_mt *child)
{
	t_mt	*parent;
	int		index;

	if (!ht || !key || !child)
		return (0);
	parent = ft_mthash_find_node(ht, key);
	if (!parent)
	{
		index = ft_mthash(key, ht->bucket_count);
		parent = ft_mtnew(key, NULL, NONE);
		if (!parent)
			return (ft_mtfree(child), 0);
		parent->values.node_type = BRANCH;
		ft_mtadd_back(&ht->buckets[index], parent);
		return (ft_mtadd_child(parent, child));
	}
	return (ft_mtadd_child(parent, child));
}

// si funciona
