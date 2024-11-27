/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew_hash_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:21:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 11:19:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_new_hash_table - Crea una nueva tabla hash.
 * @bucket_count: Número de buckets.
 *
 * Retorna un puntero a la nueva tabla hash.
 */

t_hash_table	*ft_mtnew_hash_table(size_t bucket_count)
{
	t_hash_table	*ht;

	ht = malloc(sizeof(t_hash_table));
	if (!ht)
		return (NULL);
	ht->bucket_count = bucket_count;
	ht->buckets = (t_mt **)ft_calloc(bucket_count, sizeof(t_mt *));
	ht->put = ft_mthash_insert;
	ht->get = ft_mthash_find_node;
	ht->get_data = ft_mthash_find_data;
	ht->remove = ft_mthash_remove;
	ht->free_table = ft_mtfree_hash_table;
	ht->print = ft_mtprint_hash_table;
	ht->add_child = ft_mthash_add_child;
	ht->replace_key = ft_mthash_replace_key;
	ht->replace_data = ft_mthash_replace_data;
	ht->replace_node = ft_mthash_replace_node;
	ht->add = ft_mthash_add_node;
	if (!ht->buckets)
		return (free(ht), NULL);
	return (ht);
}
