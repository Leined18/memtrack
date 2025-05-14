/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cords_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:30:22 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:30:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_cords_sub - Resta dos estructuras de coordenadas.
 * @a: Primera coordenada.
 * @b: Segunda coordenada.
 * 
 * Devuelve una nueva estructura de coordenadas que es la resta de a y b.
 */

t_cords	ft_cords_sub(t_cords a, t_cords b)
{
	t_cords	cords;

	cords.x = a.x - b.x;
	cords.y = a.y - b.y;
	cords.z = a.z - b.z;
	return (cords);
}
