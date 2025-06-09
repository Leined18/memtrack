/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:17:56 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 16:18:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_find - Busca un nodo en los slots del backup.
 * @slots: Puntero a la lista de slots.
 * @slot_count: Número de slots.
 * @target: Puntero al nodo a buscar.
 *
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_track	*ft_slot_find(t_track **slots, size_t slot_count, t_track *target)
{
    size_t	i;
    t_track	*cur;

    if (!slots || slot_count == 0 || !target || !target->key)
        return (NULL);
    i = 0;
    while (i < slot_count)
    {
        cur = slots[i];
        while (cur)
        {
            if (cur == target)
                return (cur); // Retorna el nodo si es el mismo
            cur = cur->next;
        }
        i++;
    }
    return (NULL); // Retorna NULL si no se encuentra el nodo
}