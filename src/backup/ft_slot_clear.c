/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:09:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 22:01:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void ft_slot_clear(t_slot **slots, size_t slot_count, bool free_data)
{
    size_t i;
    t_slot *current;
    t_slot *next;

    if (!slots || slot_count == 0)
        return;
    i = 0;
    while (i < slot_count)
    {
        current = slots[i];
        while (current)
        {
            next = current->top; // Guarda el siguiente nodo
            ft_slot_free(&current, free_data); // Libera el slot actual
            current = next; // Avanza al siguiente nodo
        }
        slots[i] = NULL; // Limpia el slot
        i++;
    }
    free(slots); // Libera la memoria de los slots
}