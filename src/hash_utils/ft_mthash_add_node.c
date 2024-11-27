/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_add_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:07:38 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 11:15:48 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mthash_add_node(t_hash_table *ht, t_mt *node)
{
	size_t index;

	if (!ht || !node)
		return ;
	if (ft_mthash_exists(ht, node->key))
	{
		ft_mthash_replace_node(ht, node->key, node);
		return ;
	}
	index = ft_mthash(node->key, ht->bucket_count);
	ft_mtadd_back(&ht->buckets[index], node);
}
