/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cords_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:28:03 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:28:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_cords_new - Crea una nueva estructura de coordenadas.
 * @x: Coordenada x.
 * @y: Coordenada y.
 * @z: Coordenada z.
 */

t_cords	ft_cords_new(float x, float y, float z)
{
	t_cords	cords;

	cords.x = x;
	cords.y = y;
	cords.z = z;
	return (cords);
}

