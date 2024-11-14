/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:53:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 13:53:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtswap(t_mt **list)
{
	t_mt *first;
	t_mt *second;

	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}
