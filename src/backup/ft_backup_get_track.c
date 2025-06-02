/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_get_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:22:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 14:35:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_get_track - Obtiene un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @key: Clave del nodo a buscar.
 * 
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_track	*ft_backup_get_track(t_backup *backup, const char *key)
{
    t_track	*cur;

    if (!backup || !backup->tracker || !key || ft_strlen(key) == 0)
        return (NULL);

    cur = backup->tracker;
    while (cur)
    {
        if (ft_strncmp(cur->key, key, ft_strlen(key)) == 0)
            return (cur);
        cur = cur->next;
    }
    return (NULL);
}

   