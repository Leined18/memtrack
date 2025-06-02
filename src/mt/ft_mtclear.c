/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 14:15:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtclear - Libera la memoria de mt usando la función de eliminación en backup
 * @node: Doble puntero a t_mt
 * 
 */

void	ft_mtclear(t_mt **node)
{
	t_mt *next_node;
	
	if (!node || !*node)
		return ;
	while (*node)
	{
		next_node = (*node)->next;
		ft_mtfree(*node); // Libera el nodo actual
		*node = next_node; // Avanza al siguiente nodo
	}
	*node = NULL;
}
