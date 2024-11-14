/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrotate_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 13:55:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtreverse_rotate(t_mt **list)
{
	t_mt *prev;
	t_mt *last;

	if (!list || !*list || !(*list)->next)
		return ;
	prev = NULL;
	last = *list;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *list;
	*list = last;
}
