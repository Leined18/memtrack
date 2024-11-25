/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:47 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 16:20:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mthash_remove - Elimina un nodo de la tabla hash basado en la clave.
 * @ht: Tabla hash.
 * @key: Clave del nodo a eliminar.
 *
 * Retorna 0 si tuvo éxito, -1 si falló (clave no encontrada).
 */
int	ft_mthash_remove(t_hash_table *ht, const char *key)
{
	size_t	index;
	t_mt	*current;

	if (!ht || !key)
		return (-1);
	index = ft_mthash(key, ht->bucket_count);
	current = ht->buckets[index];
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(current->key)) == 0)
		{
			if (current->prev)
				current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			if (current == ht->buckets[index]) // Si es el primero en el bucket
				ht->buckets[index] = current->next;
			current->free_data(&current->data);
			(free(current->key), free(current));
			return (0); // Eliminación exitosa
		}
		current = current->next;
	}
	return (-1); // Clave no encontrada
}
