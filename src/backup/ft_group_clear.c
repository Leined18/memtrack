/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:03:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 21:37:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_group_clear(t_group **group, bool free_data)
{
    t_group *current;

    if (!group || !*group)
        return;
    current = *group;
    while (current)
    {
        t_group *next = current->next; // Guarda el siguiente grupo
        if (free_data)
            ft_track_clear(&current->head, true); // Libera los tracks si se indica
        ft_group_free(&current, free_data); // Libera el grupo actual
        current = next; // Avanza al siguiente grupo
    }
    *group = NULL; // Limpia el puntero del grupo
}