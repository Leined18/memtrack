/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linknew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:27:37 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 11:43:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_linknew - Creates a new link.
 * @node: Pointer to the node to be linked.
 * @direction: Direction of the link (0.0 to 1.0).
 * @distance: Distance of the link.
 *
 * Returns a pointer to the newly created link.
 */

t_link	*ft_linknew(t_mt *node, float direction, float distance)
{
	t_link	*link;

	if (!node)
		return (NULL);
	link = ft_calloc(1, sizeof(t_link));
	if (!link)
		return (NULL);
	link->direction = direction;
	link->distance = distance;
	link->node = node;
	return (link);
}