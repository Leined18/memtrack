/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 14:43:43 by danpalac         ###   ########.fr       */
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
		parent->values.node_type = BRANCH;
		parent->children = child;
		child->parent = parent;
		return (1);
	}
	child->parent = parent;
	parent->values.node_type = BRANCH;
	ft_mtadd_back(&parent->children, child);
	return (1);
}

int	ft_mtadd_children(t_mt *parent, t_mt *children)
{
	if (!parent || !children)
		return (0);
	while (children)
	{
		ft_mtadd_child(parent, children);
		children = children->right;
	}
	return (1);
}
