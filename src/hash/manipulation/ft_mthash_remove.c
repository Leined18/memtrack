/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:47 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 17:05:10 by danpalac         ###   ########.fr       */
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

// falta actualizar para eliminar en cualquier parte de la lista
// elimina un nodo de la tabla hash basado en la clave
int	ft_mthash_remove_node(t_hash_table *ht, const char *key)
{
	t_mt	*current;
	t_mt	*tmp;
	int		index;

	if (!ht || !key)
		return (-1);
	index = ft_mthash_get_index(ht, key);
	if (index == -1)
		return (-1);
	current = ft_mtsearch_key(ht->buckets[index], key);
	if (!current)
		return (-1);
	tmp = current;
	if (tmp->right)
		tmp->right->left = tmp->left;
	if (tmp->left)
		tmp->left->right = tmp->right;
	if (tmp == ht->buckets[index])
		ht->buckets[index] = tmp->right;
	ft_mtfree(tmp);
	return (1); // si se elimina correctamente
}