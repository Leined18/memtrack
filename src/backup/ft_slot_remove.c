/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:27:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 18:30:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int ft_slot_remove(t_track **slots, size_t slot_count, t_track *target, bool free_target)
{
    size_t	i;

    if (!slots || slot_count == 0 || !target)
        return (0);
    i = 0;
    while (i < slot_count)
    {
        if (ft_track_remove(&slots[i], target, free_target))
            return (1); // Si se elimina el nodo, salimos
        i++;
    }
    return (0); // Retorna 0 si no se encuentra el nodo en ningún slot
}