/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:53:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 17:07:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtswap_nodes(t_mt *node1, t_mt *node2)
{
	t_mt	*tmp;

	if (!node1 || !node2)
		return ;
	tmp = node1->next;
	node1->next = node2->next;
	node2->next = tmp;
}

void	ft_mtswap(t_mt **list)
{
	t_mt *tmp;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = (*list)->next;
	ft_mtswap_nodes(*list, tmp);
}
