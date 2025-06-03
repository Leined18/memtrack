/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:46:24 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 23:47:03 by daniel           ###   ########.fr       */
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

    if (!backup || !*backup || !track)
        return ;

    if (!(*backup)->tracker)
    {
        (*backup)->tracker = track; // Si no hay tracker, lo asigna directamente
        return ;
    }
    cur = (*backup)->tracker;
    while (cur->next)
        cur = cur->next;
    cur->next = track; // Agrega el nuevo track al final de la lista
    track->next = NULL; // Asegura que el nuevo track sea el último
}
