/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcount_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:51:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:21:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtcount_node_type(t_mt *node, t_node_type type)
{
	int		count;
	t_mt	*current;

	if (!node)
		return (0);
	count = 0;
	current = node;
	while (current)
	{
		if (current->values.node_type == type)
			count++;
		if (current->children)
			count += ft_mtcount_node_type(current->children, type);
		current = current->right;
	}
	return (count);
}

int	ft_mtcount_data_type(t_mt *node, t_data_type type)
{
	int		count;
	t_mt	*current;

	if (!node)
		return (0);
	count = 0;
	current = node;
	while (current)
	{
		if (current->values.data_type == type)
			count++;
		if (current->children)
			count += ft_mtcount_data_type(current->children, type);
		current = current->right;
	}
	return (count);
}
