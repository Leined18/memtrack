/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_clear_tracks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:50:10 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 12:26:12 by danpalac         ###   ########.fr       */
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

    if (!tracks || !*tracks)
        return ;
    cur = *tracks;
    while (cur)
    {
        next = cur->next;
        if (cur->key)
            free(cur->key);
        ft_mtfree(cur->node);
        free(cur);
        cur = next;
    }
    *tracks = NULL;
}