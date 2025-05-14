/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:59:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_offset_new - Crea una nueva estructura de offset.
 * @direction: Dirección del offset (0.0 a 1.0).
 * @elevation: Elevación del offset (0.0 a 1.0).
 * @distance: Distancia del offset.
 *
 * Devuelve una nueva estructura de offset inicializada.
 */

t_offset	ft_offset_new(float direction, float elevation, float distance)
{
	t_offset	offset;

	offset.direction = direction;
	offset.elevation = elevation;
	offset.distance = distance;
	return (offset);
}