/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_clear_tracks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:50:10 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/04 00:33:19 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_clear_tracks - Libera la memoria de la lista de seguimiento del backup.
 * @tracks: Doble puntero a la lista de seguimiento del backup.
 *
 * Esta función libera la memoria ocupada por la lista de seguimiento del backup
 * y sus nodos. Se asegura de liberar todos los nodos de seguimiento y sus datos.
 */

void	ft_backup_clear_tracks(t_track **tracks)
{
    t_track	*cur;
    t_track	*next;
    t_mt *node;

    if (!tracks || !*tracks)
        return ;
    cur = *tracks;
    while (cur)
    {
        next = cur->next;
        node = cur->node;
        ft_backup_remove_track(tracks, cur, true, false);
        if (node)
        {
            node->backup = NULL; // Desvincula el nodo del backup
            ft_mtfree(node); // Libera el nodo mt asociado
        }
        cur = next;
    }
    *tracks = NULL;
}