/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkunzip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:55:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 10:55:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_stkunzip(t_stack **stack)
{
	t_stack *unzippedlist;
	t_mt *current;
	t_mt *unzipped;
	t_stack *temp_stack;

	if (!stack || !(*stack) || !(*stack)->head)
		return (NULL);
	unzippedlist = ft_stknew(NULL, "unzipped");
	if (!unzippedlist)
		return (NULL);
	while ((*stack)->size > 0)
	{
		current = (*stack)->head;
		unzipped = ft_mtunzip((current->data), current->count);
		if (unzipped)
		{
			temp_stack = ft_stknew(NULL, "temp");
			temp_stack->head = unzipped;
			ft_stkmigrate_back(&temp_stack, &unzippedlist);
			ft_stkpop(stack);
		}
		else
			ft_stkpush(stack, &unzippedlist);
	}
	return (unzippedlist);
}
