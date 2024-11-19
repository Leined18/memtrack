/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkadd_mt_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:58:36 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 10:58:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkadd_mt_back(t_stack **stack, t_mt *new)
{
	if (!stack || !new)
		return ;
	if (new)
		ft_mtpush_back(&new, &(*stack)->head);
	(*stack)->tail = ft_mtlast((*stack)->head);
	(*stack)->size = ft_mtsize((*stack)->head);
}
