/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:32:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 09:42:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces the node 'node' with 'new_node' in the list 'list'.

void	ft_mtreplace(t_mt **list, t_mt *node, t_mt *new_node)
{
    if (!list || !*list || !node || !new_node)
        return ;
    if (node->prev)
        node->prev->next = new_node;
    else
        *list = new_node;
    if (node->next)
        node->next->prev = new_node;
    new_node->prev = node->prev;
    new_node->next = node->next;
    node->prev = NULL;
    node->next = NULL;
}
