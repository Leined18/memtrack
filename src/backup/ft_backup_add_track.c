/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:46:24 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 13:02:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_add_track - Agrega un nodo de seguimiento a la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a agregar.
 * 
 * Esta función agrega un nodo de seguimiento a la lista de seguimiento del backup.
 * Se asegura de que el nodo no esté vacío y lo agrega a la lista de seguimiento.
 */

void	ft_backup_add_track(t_backup **backup, t_track *track)
{
    t_track	*cur;

    if (!backup || !track)
        return ;
    if (!(*backup)->tracker)
    {
        (*backup)->tracker = track;
        return ;
    }
    cur = (*backup)->tracker;
    while (cur->next)
        cur = cur->next;
    cur->next = track;
}
