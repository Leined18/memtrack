/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_cords_3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:33:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 18:39:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_calc_cords_3d - Calcula las coordenadas en 3D a partir de un origen, dirección, elevación y distancia.
 * @origin: Coordenadas de origen.
 * 
 * @offset: Estructura que contiene la dirección, elevación y distancia.
 * @direction: Dirección en radianes.
 * @elevation: Elevación en radianes.
 * @distance: Distancia a mover.
 *
 * Devuelve las nuevas coordenadas calculadas.
 */

t_cords ft_calc_cords_3d(t_cords origin, t_offset offset)
{
	t_cords result;
	float theta; // Dirección horizontal (plano XZ)
	float phi;   // Elevación vertical (ángulo con respecto al plano XZ)

	theta = offset.direction * 2.0f * PI;         // 0.00 a 1.00 => 0 a 2π
	phi = (offset.elevation - 0.5f) * PI;         // 0.00 a 1.00 => -π/2 a π/2
	result.x = origin.x + cosf(phi) * sinf(theta) * offset.distance; // X en plano XZ
	result.y = origin.y + sinf(phi) * offset.distance;               // Altura (Y)
	result.z = origin.z + cosf(phi) * cosf(theta) * offset.distance; // Z en plano XZ
	return result;
}

