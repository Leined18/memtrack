/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfree_hash_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:23:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 10:23:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_free_hash_table - Libera la memoria de la tabla hash.
 * @ht: Tabla hash.
 */
void	ft_mtfree_hash_table(t_hash_table *ht)
{
	t_mt *current;
	size_t i;

	if (!ht)
		return ;
	i = 0;
	while (i < ht->bucket_count)
	{
		current = ht->buckets[i];
		ft_mtclear(&current);
		i++;
	}
	free(ht->buckets);
	free(ht);
}
