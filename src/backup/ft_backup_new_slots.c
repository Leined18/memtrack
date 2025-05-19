/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_new_slots.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:03:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 10:44:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slotnew - Crea un nuevo slot.
 * @slot_count: Número de slots en el backup.
 *
 */

t_mt	**ft_backup_new_slots(size_t slot_count)
{
	t_mt	**slots;

	slots = ft_calloc(slot_count, sizeof(t_mt *));
	if (!slots)
		return (NULL);
	return (slots);
}

