/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset_elevation_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:02:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 19:03:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_offset_elevation - Devuelve la elevación de un offset.
 * @offset: Offset a evaluar.
 *
 * Devuelve la elevación del offset.
 */

float ft_offset_elevation(t_offset offset)
{
	return offset.elevation;
}

/**
 * ft_elevation_to_degrees - Convierte una elevación (0.0 a 1.0) a grados (-90° a +90°).
 * @elevation: Elevación en fracciones de vuelta.
 *
 * Devuelve la elevación en grados.
 */

float ft_elev_to_degrees(float elevation)
{
	return (elevation - 0.5f) * 180.0f;
}

/**
 * ft_degrees_to_elevation - Convierte grados (-90° a +90°) en elevación (0.0 a 1.0).
 * @degrees: Grados a convertir.
 *
 * Devuelve la elevación en fracciones de vuelta.
 */

float ft_degrees_to_elev(float degrees)
{
	return (degrees / 180.0f) + 0.5f;
}