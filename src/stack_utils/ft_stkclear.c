/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:30:38 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 12:19:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkclear(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	ft_mterase(&(*stack)->head); // Borramos todos los nodos de la pila
	free((*stack));
		// Finalmente liberamos la estructura de la pila
	(*stack) = NULL;
}
