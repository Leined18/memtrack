/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cords_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:09:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 17:10:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_cords_distance - Calcula la distancia entre dos coordenadas.
 * @a: Primera coordenada.
 * @b: Segunda coordenada.
 *
 * Devuelve la distancia entre las dos coordenadas.
 */

float	ft_cords_distance(t_cords a, t_cords b)
{
	float	distance;

	distance = sqrtf(powf(b.x - a.x, 2) + powf(b.y - a.y, 2) + powf(b.z - a.z, 2));
	return (distance);
}
