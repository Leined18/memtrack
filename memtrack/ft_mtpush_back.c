/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:58:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 15:04:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtpush_back(t_mt **src, t_mt **dest)
{
	t_mt *node_to_move;
	t_mt *current;

	if (!src || !*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	node_to_move->next = NULL;
	if (!*dest)
	{
		*dest = node_to_move;
		return ;
	}
	current = *dest;
	while (current->next)
		current = current->next;
	current->next = node_to_move;
}
