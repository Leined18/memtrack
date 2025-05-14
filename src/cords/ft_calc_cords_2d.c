/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_cords_2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:41:08 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:58:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_calc_cords_2d - Calcula las coordenadas en 2D a partir de un origen, dirección y distancia.
 * @origin: Coordenadas de origen.
 * @direction: Dirección en radianes.
 * @distance: Distancia a mover.
 *
 * Devuelve las nuevas coordenadas calculadas.
 */

t_cords	ft_calc_cords_2d(t_cords origin, t_offset offset)
{
	t_cords result;

	result.x = origin.x + cosf(offset.direction * TWO_PI) * offset.distance;
	result.y = origin.y + sinf(offset.direction * TWO_PI) * offset.distance;
	result.z = origin.z;
	return (result);
}
