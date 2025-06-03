/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_remove_track.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:20:00 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/04 00:36:21 by daniel           ###   ########.fr       */
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

void	ft_backup_remove_track(t_track **tracker, t_track *target, bool freec_target, bool freec_node)
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
            if (freec_target)
                ft_backup_freec_track(cur, freec_node); // Libera el nodo de seguimiento
            return ;
        }
        prev = cur;
        cur = cur->next; // Avanza al siguiente nodo
    }
}

