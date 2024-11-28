/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_update_duplicates.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:51:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 14:51:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mthash_update_duplicates(t_hash_table *ht)
{
	size_t	i;
	t_mt	*current;
	char	*new_key;

	if (!ht)
		return ;
	i = 0;
	while (i < ht->bucket_count)
	{
		current = ht->buckets[i];
		while (current)
		{
			if (ft_mthash_count(ht, current->key) > 1)
			{
				new_key = ft_mtnew_original_key(current->key, ht);
				if (new_key)
				{
					free(current->key);     // Liberamos la clave antigua
					current->key = new_key; // Asignamos la nueva clave
				}
			}
			current = current->next;
		}
		i++;
	}
}
