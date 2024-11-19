/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:45:37 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 10:47:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void    ft_stkpop(t_stack **stack)
{
    if (!stack || !(*stack) || !(*stack)->head)
        return ;
    ft_mtpop(&(*stack)->head);
    (*stack)->tail = ft_mtlast((*stack)->head);
    (*stack)->size = ft_mtsize((*stack)->head);
}
