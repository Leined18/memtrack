/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset_new_degrees.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:52:37 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 19:05:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"


/**
 * ft_offset_new_degrees - Crea un nuevo offset a partir de dirección, elevación y distancia en grados.
 * @d_direction: Dirección en grados (0° a 360°).
 * @d_elevation: Elevación en grados (-90° a +90°).
 * @distance: Distancia del offset.
 *
 * Devuelve una nueva estructura de offset inicializada.
 */

t_offset	ft_offset_new_degrees(float d_direction, float d_elevation, float distance)
{
	t_offset	result;

	result.direction = ft_degrees_to_dir(d_direction);
	result.elevation = ft_degrees_to_elev(d_elevation);
	result.distance = distance;
	return (result);
}
