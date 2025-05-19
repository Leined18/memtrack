/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_get_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:22:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 13:24:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_get_track - Obtiene un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a buscar.
 * 
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_track	*ft_backup_get_track(t_backup *backup, t_mt *node)
{
    t_track	*cur;

    if (!backup || !backup->tracker || !node)
        return (NULL);

    cur = backup->tracker;
    while (cur)
    {
        if (cur->node == node)
            return (cur);
        cur = cur->next;
    }
    return (NULL);
}

   