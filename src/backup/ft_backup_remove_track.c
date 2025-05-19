/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_remove_track.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:20:00 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 13:20:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_remove_track - Elimina un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a eliminar.
 *
 * Esta función elimina un nodo de la lista de seguimiento del backup y libera
 * su memoria. Se asegura de eliminar el nodo de la lista y liberar su memoria.
 */

void	ft_backup_remove_track(t_backup **backup, t_track *node)
{
    t_track	*cur;
    t_track	*prev;

    if (!backup || !(*backup)->tracker || !node)
        return ;
    cur = (*backup)->tracker;
    prev = NULL;
    while (cur)
    {
        if (cur == node)
        {
            if (prev)
                prev->next = cur->next;
            else
                (*backup)->tracker = cur->next;
            break ;
        }
        prev = cur;
        cur = cur->next;
    }
    if (cur)
    {
        free(cur->key);
        free(cur);
    }
}

