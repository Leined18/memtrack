/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_get_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:22:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 10:30:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_get_track - Obtiene un nodo de la lista de seguimiento del backup.
 * @track: Puntero a la lista de seguimiento del backup.
 * @key: Clave del nodo a buscar.
 * 
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_track	*ft_backup_get_track(t_track *track, const char *key)
{
    t_track    *cur;
    
    if (!track || !key)
        return (NULL); // Retorna NULL si no hay seguimiento o clave
    cur = track;
    while (cur)
    {
        if (ft_strequ(cur->node->key, key))
            return (cur); // Retorna el nodo encontrado
        cur = cur->next; // Avanza al siguiente nodo
    }
    return (NULL);
}

   