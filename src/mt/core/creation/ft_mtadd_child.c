/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 13:15:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// añade un hijo a un nodo de la tabla hash
int	ft_mtadd_child(t_mt *parent, t_mt *child)
{
	if (!parent || !child)
		return (0);
	if (!parent->children)
	{
		if (parent->values.node_type != ROOT)
			parent->values.node_type = BRANCH;
		child->values.node_type = LEAF;
		parent->children = child;
		child->parent = parent;
		return (1);
	}
	if (parent->values.node_type != ROOT)
		parent->values.node_type = BRANCH;
	child->values.node_type = LEAF;
	ft_mtadd_back(&parent->children, child);
	return (1);
}
