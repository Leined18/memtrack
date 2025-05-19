/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add_slot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:33:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 11:16:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_hash - Calcula el hash de un nodo.
 * @node: Puntero al nodo.
 * 
 * Retorna el hash del nodo.
 */


size_t		ft_hash(t_mt *node)
{
	size_t		hash;
	size_t		i;

	if (!node || !node->key)
		return (0);
	hash = 0;
	i = 0;
	while (node->key[i])
	{
		hash += node->key[i];
		i++;
	}
	return (hash);
}

/**
 * ft_backup_add_slot - Agrega un nodo a la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a agregar.
 * 
 */

void	ft_backup_add_slot(t_backup *backup, t_mt *node)
{
    size_t index;

	if (!backup || !node || !backup->slots || backup->slot_count == 0)
		return ;
	index = 0;
    index = ft_hash(node) % backup->slot_count;
    if (index >= backup->slot_count)
        index = backup->slot_count - 1;
    if (backup->slots)
        ft_mtadd_back(&backup->slots[index], &node, NULL);
}
    