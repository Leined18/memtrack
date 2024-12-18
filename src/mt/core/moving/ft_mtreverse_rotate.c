/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:57:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the last element of the list to the first position.
void	ft_mtreverse_rotate(t_mt **list)
{
	t_mt	*last;

	if (!list || !*list || !(*list)->vect.right)
		return ;
	last = *list;
	while (last->vect.right)
		last = last->vect.right;
	last->vect.left->vect.right = NULL;
	last->vect.left = NULL;
	last->vect.right = *list;
	(*list)->vect.left = last;
	*list = last;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtreverse_rotate(&stacka);
// stacka = "sa" -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"
