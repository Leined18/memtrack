/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:30:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 16:30:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_offset_mul - Multiplica dos estructuras de offset.
 * @a: Primer offset.
 * @b: Segundo offset.
 * 
 * Devuelve un nuevo offset que es el producto de a y b.
 */

t_offset	ft_offset_mul(t_offset a, t_offset b)
{
	t_offset	offset;

	offset.direction = a.direction * b.direction;
	offset.elevation = a.elevation * b.elevation;
	offset.distance = a.distance * b.distance;
	return (offset);
}