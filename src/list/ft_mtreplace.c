/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:32:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 21:10:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces the node 'node' with 'new_node' in the list 'list'.

void	ft_mtreplace_connections(t_mt **list, t_mt *node, t_mt *new_node)
{
	t_mt	*old_node;

	if (!node || !new_node)
		return ;
	old_node = ft_mtdisconnect(&node);
	ft_mtfree(&old_node);
	ft_mtconnect_left(&new_node, node->left);
	ft_mtconnect_right(&new_node, node->right);
	ft_mtconnect_parent(&new_node, node->parent);
	ft_mtconnect_child(&new_node, node->children);
	ft_mtfree(&node);
	(*list) = new_node;
}

void	ft_mtreplace(t_mt **list, t_mt *node, t_mt *new_node)
{
	if (!list || !node || !new_node)
		return ;
	ft_mtreplace_connections(list, node, new_node);
}
