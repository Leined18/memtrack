/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_replace_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:08:54 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 11:21:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mthash_replace_node(t_hash_table *ht, const char *key, t_mt *node)
{
	size_t index;

	if (!ht || !key || !node)
		return ;
	index = ft_mthash(key, ht->bucket_count);
	if (!ft_mthash_exists(ht, key))
	{
		ft_mtadd_back(&ht->buckets[index], node);
		return ;
	}
	ft_mthash_replace_data(ht, key, node->data, node->type);
	ft_mthash_replace_key(ht, key, node->key);
    free(node->key);
    free(node);
}
// This function replaces the node with the key 'key' with the