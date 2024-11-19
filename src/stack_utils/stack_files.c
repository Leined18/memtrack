/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:50:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 07:51:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_stkhead(t_stack *stack)
{
	if (stack && stack->head)
		return (stack->head);
	return (NULL);
}

t_mt	*ft_stktail(t_stack *stack)
{
	if (stack && stack->tail)
		return (stack->tail);
	return (NULL);
}

t_mt	*ft_stkprev(t_mt *node)
{
	if (node)
		return (node->prev);
	return (NULL);
}

void	ft_stkadd_back(t_stack *stack, t_mt *new)
{
	if (!stack || !new)
		return ;
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
		return ;
	}
	stack->tail->next = new;
	new->prev = stack->tail;
	stack->tail = new;
}

void	ft_stkadd_front(t_stack *stack, t_mt *new)
{
	if (!stack || !new)
		return ;
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
		return ;
	}
	stack->head->prev = new;
	new->next = stack->head;
	stack->head = new;
}

void	ft_stkrmmt(t_stack *stack, t_mt *node)
{
	if (!node || !stack)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == stack->head)
		stack->head = node->next;
	if (node == stack->tail)
		stack->tail = node->prev;
	free(node);
	stack->size--;
}

void	ft_stkclear(t_stack *stack)
{
	ft_mterase(&stack->head);
}