/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:32:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:18:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces the node 'node' with 'new_node' in the list 'list'.

void	ft_mtreplace(t_mt *node, t_mt *new_node)
{
    t_mt *temp;
	if (!node || !new_node)
		return ;
    temp = node->left;
    if (temp)
        temp->right = new_node;
    new_node->left = temp;
    new_node->right = node->right;
    if (node->right)
        node->right->left = new_node;
    ft_mtfree(node);
}
