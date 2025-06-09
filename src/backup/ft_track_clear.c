/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_clear.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:50:10 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/04 00:33:19 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_track_clear - Libera la memoria de la lista de seguimiento del backup.
 * @tracks: Doble puntero a la lista de seguimiento del backup.
 *
 * Esta función libera la memoria ocupada por la lista de seguimiento del backup
 * y sus nodos. Se asegura de liberar todos los nodos de seguimiento y sus datos.
 */

void	ft_track_clear(t_track **tracks, bool free_data)
{
    t_track	*cur;
    t_track	*next;
    t_mt    *node;

    if (!tracks || !*tracks)
        return ;
    cur = *tracks;
    while (cur)
    {
        if (cur->node && free_data)
        {
            node = cur->node;
            cur->node = NULL;
            ft_mtclear(&node);
        }
        next = cur->next;
        ft_track_free(&cur, false);
        cur = next;
    }
    *tracks = NULL;
}