/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:27:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 22:19:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int ft_slot_remove(t_slot **slots, size_t slot_count, t_slot *target, bool free_target)
{
    size_t	i;

    if (!slots || slot_count == 0 || !target)
        return (0);
    i = 0;
    while (i < slot_count)
    {
        t_slot *cur = slots[i];
        while (cur)
        {
            if (cur == target) // Verifica si el nodo actual es el mismo que el objetivo
            {
                if (free_target)
                {
                    slots[i] = cur->top; // Elimina el nodo del slot
                    ft_slot_free(&cur, true); // Libera la memoria del nodo
                }
                else
                    slots[i] = cur->top; // Elimina el nodo del slot sin liberar memoria
                return (1); // Retorna 1 si se elimina correctamente
            }
            cur = cur->top; // Avanza al siguiente nodo en el slot
            
        }
        i++;
    }
    return (0); // Retorna 0 si no se encuentra el nodo en ningún slot
}