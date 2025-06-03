/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_new_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:41:27 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 21:53:55 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_tracknew - Crea un nuevo nodo de seguimiento para el backup.
 * @key: Clave del nodo.
 * @node: Puntero al nodo a agregar.
 * @return : puntero al t_track o NULL si no se puede crear.
*/

t_track *ft_backup_new_track(const char *key, t_mt *node)
{
    t_track	*track;

    if (!key || !node)
        return (NULL);
    track = ft_calloc(1, sizeof(t_track));
    if (!track)
        return (NULL);
    track->key = ft_strdup(key);
    if (!track->key)
        return (freec(track), NULL);
    track->node = node;
    track->next = NULL;
    return (track);
}
