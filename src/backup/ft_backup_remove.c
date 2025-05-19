/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:23 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 13:38:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_remove - Elimina un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a eliminar.
 * 
 * Esta función elimina un nodo de la lista de seguimiento del backup y libera
 * su memoria. Se asegura de eliminar el nodo de la lista y liberar su memoria.
 */

void	ft_backup_remove(t_backup **backup, t_mt *node)
{
    size_t	index;
    t_track   *track;

	if (!backup || !(*backup)->slots || !node->key)
		return ;
	index = ft_hash_str(node->key) % (*backup)->slot_count;
	node = ft_backup_get(*backup, node->key);
    if (!node)
        return ;
    ft_mtremove(&(*backup)->slots[index], node);
    track = ft_backup_get_track(*backup, node);
    ft_backup_remove_track(backup, track);
    ft_mtdelete(node);
    (*backup)->item_count--;
}