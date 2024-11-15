/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 11:04:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtremove(t_mt **lst, void *data, int *(cmp)(), size_t n)
{
	t_mt	*current;
	t_mt	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (!cmp(current->data, data, n))
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			ft_mtdel_data(&current->data);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
