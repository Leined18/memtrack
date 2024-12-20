/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:26:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// añade un hijo a un nodo de la tabla hash
int	ft_mtadd_child(t_mt *parent, t_mt *child)
{
	if (!parent || !child)
		return (0);
	if (!parent->vect.down)
	{
		if (parent->values.node_type != ROOT)
			parent->values.node_type = BRANCH;
		child->values.node_type = LEAF;
		parent->vect.down = child;
		child->vect.up = parent;
		return (1);
	}
	if (parent->values.node_type != ROOT)
		parent->values.node_type = BRANCH;
	child->values.node_type = LEAF;
	ft_mtadd_right(&parent->vect.down, child);
	return (1);
}
