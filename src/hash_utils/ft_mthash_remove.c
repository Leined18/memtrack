/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:47 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 13:31:04 by danpalac         ###   ########.fr       */
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
int	ft_mthash_remove(t_hash_table *ht, const char *key)
{
	t_mt	*current;

	if (!ht || !key)
		return (-1);
	current = ft_mthash_find_node(ht, key);
	if (!current)
        return (-1);
    current->prev->next = current->next; // desanclamos el nodo
    current->next->prev = current->prev; // Eliminamos el nodo
    free(current->key);
    ft_mtdel_by_type(&current->data, current->type);
    free(current);
	return (1); // si se elimina correctamente
}
