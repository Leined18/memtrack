/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcount_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:51:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 17:29:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"


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
		if (current->values.data_type == (int)type)
			count++;
		if (current->children)
			count += ft_mtcount_data_type(current->children, type);
		current = current->right;
	}
	return (count);
}
