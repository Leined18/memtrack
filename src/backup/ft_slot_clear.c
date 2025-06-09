/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:09:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 18:11:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void ft_slot_clear(t_track **slots, size_t slot_count, bool free_data)
{
    size_t i;

    if (!slots || slot_count == 0)
        return;
    i = 0;
    while (i < slot_count)
    {
        t_track *current = slots[i];
        ft_track_clear(&current, free_data); // Limpia el slot actual
        slots[i] = NULL; // Limpia el slot
        i++;
    }
    free(slots); // Libera la memoria de los slots
}