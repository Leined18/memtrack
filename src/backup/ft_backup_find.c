/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:17:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 16:17:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_find - Busca un nodo en el backup por su clave.
 * @backup: Puntero a la estructura de backup.
 * @target: Puntero al nodo a buscar.
 *
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

 
t_track	*ft_backup_find(t_backup *backup, t_track *target)
{
    t_track	*found;

    if (!backup || !target || !target)
        return (NULL);
    found = ft_track_find(backup->tracker, target);
    if (!found)
    {
        found = ft_slot_find(backup->slots, backup->slot_count, target);
        if (!found)
            return (NULL); // Retorna NULL si no se encuentra el nodo
    }
    return (found);
}   