/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:11:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the last element of the list to the first position.
void	ft_mtreverse_rotate(t_mt **list)
{
	t_mt	*prev;
	t_mt	*last;

	if (!list || !*list || !(*list)->next)
		return ;
	prev = NULL;
	last = *list;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *list;
	*list = last;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtreverse_rotate(&stacka);
// stacka = "sa" -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"
