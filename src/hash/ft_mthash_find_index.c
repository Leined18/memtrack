/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_find_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:04:02 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 11:03:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// find the index where the key is, no matter if is the key is in a child
int	ft_mthash_get_index(t_hash_table *ht, const char *key)
{
	size_t index;
	t_mt *current;

	if (!ht || !key)
		return (-1);
	index = 0;
	while (index < ht->bucket_count)
	{
		current = ht->buckets[index];
		while (current)
		{
			if (ft_mtsearch_mt(current, key))
				return (index);
			current = current->right;
		}
		index++;
	}
	return (-1);
}
