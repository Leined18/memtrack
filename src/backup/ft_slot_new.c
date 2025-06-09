/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:07:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 16:08:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_new - Crea un nuevo slot.
 * @slot_count: Número de slots en el backup.
 *
 */

t_track	**ft_slot_new(size_t slot_count)
{
	t_track	**slots;

	slots = ft_calloc(slot_count, sizeof(t_track *));
	if (!slots)
		return (NULL);
	return (slots);
}

