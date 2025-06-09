/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:22:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 16:03:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_search_track - Obtiene un nodo de la lista de seguimiento del backup.
 * @track: Puntero a la lista de seguimiento del backup.
 * @key: Clave del nodo a buscar.
 * 
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_track	*ft_track_search(t_track *track, const char *key)
{
    t_track    *cur;
    
    if (!track || !key)
        return (NULL);
    cur = track;
    while (cur)
    {
        while (cur && cur->key && ft_strequ(cur->key, key))
            return (cur);
        cur = cur->next;
    }
    return (NULL);
}

   