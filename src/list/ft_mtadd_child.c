/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 12:41:11 by danpalac         ###   ########.fr       */
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
		parent->children = child;
        child->parent = parent;
        child->left = NULL;
        child->right = NULL;
		return (1);
	}
	if (ft_mtsearch_mt(parent->children, child->key, ft_mtcmp_key))
		child->key = ft_mtnew_original_key(child->key, parent);
    child->parent = parent;
	ft_mtadd_back(&parent->children, child);
	return (1);
}
