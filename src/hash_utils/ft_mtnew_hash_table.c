/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew_hash_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:21:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 13:39:16 by danpalac         ###   ########.fr       */
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
	if (!ht->buckets)
		return (free(ht), NULL);
	return (ht);
}
