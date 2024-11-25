/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:23:07 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 20:47:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_hash_find - Busca un nodo en la tabla hash.
 * @ht: Tabla hash.
 * @key: Clave del nodo.
 *

	* Retorna un puntero a los datos si encuentra el nodo o NULL si no lo encuentra.
 */
void	*ft_mthash_find(t_hash_table *ht, const char *key)
{
	size_t index;
	t_mt *current;
	t_mt *result;

	if (!ht || !key)
		return (NULL);
	index = ft_mthash(key, ht->bucket_count);
	current = ht->buckets[index];
	while (current)
	{
		result = ft_mtsearch_mt(current, key, ft_mtcmp_key);
		if (result)
			return (current);
		current = current->next;
	}
	return (NULL);
}
