/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset_inverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:32:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 16:59:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_offset_inverse - Invierte un offset.
 * @o: Offset a invertir.
 *
 * Devuelve el offset invertido.
 */

t_offset	ft_offset_inverse(t_offset o)
{
	t_offset	inv;

	inv.direction = fmodf(o.direction + 0.5f, 1.0f); // Gira 180° horizontalmente
	inv.elevation = 1.0f - o.elevation;              // Refleja verticalmente
	inv.distance = o.distance;
	return (inv);
}
