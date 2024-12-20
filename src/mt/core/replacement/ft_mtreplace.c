/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:32:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:27:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces the node 'node' with 'new_node' in the list 'list'.

void	ft_mtreplace(t_mt **list, t_mt *node, t_mt *new_node)
{
	t_mt	*temp;

	if (!node || !new_node)
		return ;
	temp = node->vect.left;
	if (temp)
		temp->vect.right = new_node;
	else
		*list = new_node;
	new_node->vect.left = temp;
	new_node->vect.right = node->vect.right;
	if (node->vect.right)
		node->vect.right->vect.left = new_node;
	ft_mtdelete(&node);
}
