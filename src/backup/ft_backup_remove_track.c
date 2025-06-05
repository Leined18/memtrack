/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_remove_track.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:20:00 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 10:18:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_remove_track - Elimina un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @target: Puntero al nodo a eliminar.
 *
 * Esta función elimina un nodo de la lista de seguimiento del backup y libera
 * su memoria. Se asegura de eliminar el nodo de la lista y liberar su memoria.
 */

void	ft_backup_remove_track(t_track **tracker, t_track *target, bool free_target, bool free_node)
{
    t_track	*cur;
    t_track	*prev;

    if (!tracker || !*tracker || !target)
        return ;

    cur = *tracker;
    prev = NULL;
    while (cur)
    {
        if (ft_mtkeycmp(cur->node, target->key))
        {
            if (prev)
                prev->next = cur->next; // Elimina el nodo actual de la lista
            else
                *tracker = cur->next; // Si es el primer nodo, actualiza el tracker
            if (free_target)
                ft_backup_free_track(cur, free_node); // Libera el nodo de seguimiento
            return ;
        }
        prev = cur;
        cur = cur->next; // Avanza al siguiente nodo
    }
}

