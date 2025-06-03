/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:23 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/04 00:17:32 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_remove - Elimina un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @target: Puntero al nodo a eliminar.
 * 
 * Esta función elimina un nodo de la lista de seguimiento del backup y libera
 * su memoria. Se asegura de eliminar el nodo de la lista y liberar su memoria.
 */

void	ft_backup_remove(t_backup **backup, t_mt *target, bool freec_target)
{
    const char	*key;
    t_track    *tmp_track;

	if (!backup || !target->key)
		return ;
	target = ft_backup_get(*backup, target->key);
    if (!target)
        return ;
    key = target->key;
	if (freec_target)
		target->backup = NULL;
    tmp_track = ft_backup_get_track((*backup)->tracker, key);
	ft_backup_remove_slot(backup, target, false);
    ft_backup_remove_track(&(*backup)->tracker, tmp_track,
        true, freec_target);
    (*backup)->item_count--;
}