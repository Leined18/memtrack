/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtlast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:00:48 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 16:05:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtlast - Devuelve el último nodo de la lista.
 * @node: Doble puntero a la lista de nodos.
 * @direction: Dirección del nodo.
 * @move: Indica si se debe mover el puntero al último nodo.
 *
 * Retorna el último nodo de la lista.
 */

t_mt	*ft_mtlast(t_mt **node, float direction, float elevation, bool move)
{
	t_mt	*last;
	t_link	*link;

	if (!node || !*node)
		return (NULL);
	last = *node;
	while (last)
	{
		link = ft_link_offset(&last->links, ft_offset_new(direction, elevation, 0.0));
		if (link)
			last = link->node;
		else
			break ;
	}
	if (move)
		*node = last;
	return (last);
}