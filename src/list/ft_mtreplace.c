/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:32:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 13:56:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces the node 'node' with 'new_node' in the list 'list'.

void	ft_mtreplace(t_mt *node, t_mt *new_node)
{
	if (!node || !new_node)
		return ;
    ft_mtfree(node);
	node = ft_mtdup(new_node);
    ft_mtfree(new_node);
}
