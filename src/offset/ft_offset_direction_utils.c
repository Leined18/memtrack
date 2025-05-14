/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset_direction_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:00:20 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 19:03:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_direction_to_degrees - Convierte una dirección (0.0 a 1.0) a grados (0° a 360°).
 * @direction: Dirección en fracciones de vuelta.
 *
 * Devuelve la dirección en grados.
 */

float ft_dir_to_degrees(float direction)
{
	return direction * 360.0f;
}

/**
 * ft_offset_direction - Devuelve la dirección de un offset.
 * @offset: Offset a evaluar.
 *
 * Devuelve la dirección del offset.
 */

 
float ft_degrees_to_dir(float degrees)
{
    return degrees / 360.0f;
}

/**
 * ft_offset_direction - Devuelve la dirección de un offset.
 * @offset: Offset a evaluar.
 *
 * Devuelve la dirección del offset.
 */

float ft_offset_direction(t_offset offset)
{
	return offset.direction;
}

/**
 * ft_offset_elevation - Devuelve la elevación de un offset.
 * @offset: Offset a evaluar.
 *
 * Devuelve la elevación del offset.
 */

 

 