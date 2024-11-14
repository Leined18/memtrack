/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 17:17:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtpush(t_mt **src, t_mt **dest)
{
	t_mt *node_to_move;

	if (!src || !*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	node_to_move->next = *dest;
	*dest = node_to_move;
}
