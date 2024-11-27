/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcount_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:51:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 17:56:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtcount_type(t_mt *node, t_data_type type)
{
	int		count;
	t_mt	*current;

	if (!node)
		return (0);
	count = 0;
	current = node;
	while (current)
	{
		if (current->type == type)
			count++;
		if (current->type == BRANCH && current->data)
			count += ft_mtcount_type((t_mt *)current->data, type);
		current = current->next;
	}
	return (count);
}
