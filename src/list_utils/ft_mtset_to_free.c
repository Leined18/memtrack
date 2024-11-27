/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtset_to_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:56:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 19:56:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtset_to_free(t_mt *mt, int to_free)
{
	t_mt *current;

	if (!mt)
		return ;
	current = mt;
	while (current)
	{
		current->to_free = to_free;
		if (current->type == BRANCH && current->data)
			ft_mtset_to_free((t_mt *)current->data, to_free);
		current = current->next;
	}
}
