/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcount_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:16:23 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 12:38:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtcount_node - Counts the number of nodes in the list.
 * @lst: List of nodes to count.
 * Return: The number of nodes in the list.
 * use ft_mtfold to count the number of nodes in the list
 */

static int	match_count(t_mt *node, void *param)
{
	(void)param;
	if (node)
		return (1);
	return (0);
}

size_t	ft_mtcount_node(t_mt *lst)
{
	if (!lst)
		return (0);
	return (ft_mtfold(lst, NULL, match_count));
}
