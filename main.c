/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 18:22:31 by danpalac         ###   ########.fr       */
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
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = ft_stknew();
	stackb = ft_stknew();

	ft_stkadd_back(stacka, ft_mtnew("miau"));
	ft_stkadd_back(stacka, ft_mtnew("guau"));

	ft_stkadd_back(stackb, ft_mtnew("pi"));
	ft_stkadd_back(stackb, ft_mtnew("mu"));

	ft_mtprint(ft_stkhead(stacka), 0, " ");
	ft_mtprint(ft_stkhead(stackb), 0, " ");

	ft_mtprint(chaosmatrix(0,0,1), 0, " ");
	return (0);
}
