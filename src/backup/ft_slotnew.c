/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slotnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:03:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:15:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slotnew - Crea un nuevo slot.
 * @slot_count: Número de slots en el backup.
 *
 */

t_slot	*ft_slotnew(size_t slot_count)
{
	t_slot	*slot;

	slot = ft_calloc(slot_count, sizeof(t_slot));
	if (!slot)
		return (NULL);
	slot->node = NULL;
	slot->next = NULL;
	return (slot);
}
