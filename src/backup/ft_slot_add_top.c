/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_add_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:08:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 20:08:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_slot_add_top(t_track **slots, size_t slot_count, t_track *node)
{
    size_t	i;

    if (!slots || slot_count == 0 || !node)
        return ;
    i = ft_hash_str(node->id) % slot_count;
    if (i >= slot_count)
        i = slot_count - 1;
    node->top = slots[i];
    slots[i] = node;
}
