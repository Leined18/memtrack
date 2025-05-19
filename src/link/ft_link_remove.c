/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:31:34 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 13:36:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_link_remove - Elimina un nodo de la lista enlazada.
 * @node: Puntero al nodo a eliminar.
 * @target: Nodo objetivo a eliminar.
 *
 * Esta función elimina un nodo de la lista enlazada y libera su memoria.
 * Se asegura de eliminar el nodo de la lista y liberar su memoria.
 */

void	ft_link_remove(t_link **node, t_link *target)
{
    t_link	*cur;
    t_link	*prev;

    if (!node || !*node || !target)
        return ;
    cur = *node;
    prev = NULL;
    while (cur)
    {
        if (cur == target)
        {
            if (prev)
                prev->next = cur->next;
            else
                *node = cur->next;
            break ;
        }
        prev = cur;
        cur = cur->next;
    }
    if (cur)
        free(cur);
}
