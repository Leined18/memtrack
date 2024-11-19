/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:00:22 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 11:00:28 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkprint(t_stack *stack, int type, char *c)
{
	if (!stack)
	{
		ft_printf("(Stack is NULL)\n");
		return ;
	}
	ft_printf("Stack size: %d\n", stack->size);
	ft_printf("Stack head: %p\n", stack->head);
	ft_printf("Stack Name: %s\n", stack->name);
	ft_mtprint(stack->head, type, c);
	ft_printf("Stack tail: %p\n", stack->tail);
	ft_printf("\n");
}
