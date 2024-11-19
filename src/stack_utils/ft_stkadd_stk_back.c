/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkadd_stk_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:59:36 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 10:59:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkadd_stk_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	ft_stkmigrate_back(&new, stack);
}
