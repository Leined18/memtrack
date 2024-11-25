/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:22:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 17:45:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_hash_insert - Inserta un nodo en la tabla hash.
 * @ht: Tabla hash.
 * @key: Clave del nodo.
 * @data: Datos a almacenar.
 * @size: Tamaño de los datos.
 *
 * Retorna 0 si tuvo éxito, -1 si falló.
 */

int	ft_mthash_insert(t_hash_table *ht, const char *key, void *data,
		t_data_type type)
{
	size_t	index;
	t_mt	*current;
	t_mt	*new_node;

	if (!ht || !key || !data)
		return (-1);
	index = ft_mthash(key, ht->bucket_count);
	current = ht->buckets[index];
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(current->key)) == 0)
		{
			if (type == STRING)
				(ft_mtdel_data(&current->data), current->data = data);
			else if (type == LIST)
				(ft_mtdel_list(&current->data), current->data = data);
			return (0);
		}
		current = current->next;
	}
	new_node = ft_mtnew(key, data, type);
	if (!new_node)
		return (-1);
	ft_mtadd_back(&ht->buckets[index], new_node);
	return (0);
}