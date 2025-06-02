/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_free_track.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:26:46 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 14:27:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_free_track - Libera la memoria de un nodo de seguimiento del backup.
 * @track: Puntero al nodo de seguimiento a liberar.
 *
 * Esta función libera la memoria ocupada por un nodo de seguimiento del backup
 * y sus datos asociados. Se asegura de liberar el nodo y sus campos clave.
 */

void	ft_backup_free_track(t_track *track, bool free_node)
{
    if (!track)
        return ;
    if (track->key)
        free(track->key);
    if (track->node && free_node)
        ft_mtfree(track->node);
    free(track);
}
