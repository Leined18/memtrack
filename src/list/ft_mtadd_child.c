/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 12:00:20 by danpalac         ###   ########.fr       */
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
	if (ft_mtsearch_mt(parent->children, child->key))
		child->key = ft_mtnew_original_key(child->key, parent);
	child->parent = parent;
    parent->values.node_type = BRANCH;
	ft_mtadd_back(&parent->children, child);
	return (1);
}
