/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:05:48 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

t_stack	*ft_stknew(void)
{
	t_stack	*stack;

	stack = (t_stack *)chaosmatrix(1, sizeof(t_stack), 0);
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

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

int	main(void)
{
	t_mt	*stacka;
	t_mt	*tmp;

	stacka = NULL;
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	ft_mtpush_data(&stacka, "miau");
	ft_mtpush_data(&stacka, "guau");
	ft_mtpush_data(&stacka, "mu");
	ft_mtpush_data(&stacka, "le");
	ft_mtpush_data(&stacka, "asd");
	ft_mtpush_data(&stacka, "ñe");
	ft_mtpush_data(&stacka, "sa");
	ft_mtprint(stacka, 1, " -> ");
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	chaosmatrix(-1, 0, 0);
	ft_mterase(&stacka);
	ft_mtprint(stacka, 1, " -> ");
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	return (0);
}
