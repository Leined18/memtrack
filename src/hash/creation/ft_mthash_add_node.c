/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_add_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:07:38 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:26:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"


// Añade el nodo a la tabla hash
void	ft_mthash_add_node(t_hash_table *ht, t_mt *node)
{
	size_t	index;

	if (!ht || !node)
		return ;
	if (ft_mthash_exists(ht, node->key))
		node->key = ft_mthash_new_original_key(node->key, ht);
	index = ft_mthash(node->key, ht->bucket_count);
	ft_mtadd_right(&ht->buckets[index], node);
}
