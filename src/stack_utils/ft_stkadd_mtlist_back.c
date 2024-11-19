/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkadd_mtlist_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:58:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 10:59:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkadd_mtlist_back(t_stack **stack, t_mt **new)
{
	t_mt *tmp;

	if (!stack || !new)
		return ;
	tmp = *new;
	while (tmp)
	{
		if (!(*stack))
			(*stack) = ft_stknew(NULL, "temp");
		ft_mtpush_back(&tmp, &(*stack)->head);
	}
	(*stack)->tail = ft_mtlast((*stack)->head);
	(*stack)->size = ft_mtsize((*stack)->head);
}
