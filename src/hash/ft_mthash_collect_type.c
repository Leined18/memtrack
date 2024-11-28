/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_collect_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:49:02 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 20:39:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mthash_collect_types
	- Recolecta nodos de un tipo específico desde una tabla hash.
 * @ht: Tabla hash a procesar.
 * @type: Tipo de dato que se desea recolectar.
 *
 * Return: Lista enlazada de nodos recolectados.
 */
t_mt	*ft_mthash_collect_types(t_hash_table *ht, t_data_type type)
{
	size_t	i;
	t_mt	*collected;
	t_mt	*current;
	t_mt	*temp;

	if (!ht)
		return (NULL);
	i = 0;
	collected = NULL;
	while (i < ht->bucket_count)
	{
		current = ht->buckets[i];
		while (current)
		{
			// Recolectamos los nodos del bucket actual.
			temp = ft_mtcollect_types(current, type);
			ft_mtmigrate_back(&temp, &collected);
			current = current->next;
		}
		i++;
	}
	return (collected);
}
