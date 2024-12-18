/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:58:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the first element of the list to the last position.
void	ft_mtrotate(t_mt **list)
{
	t_mt	*first;
	t_mt	*last;

	if (!list || !*list || !(*list)->vect.right)
		return ;
	first = *list;
	last = *list;
	while (last->vect.right)
		last = last->vect.right;
	*list = first->vect.right;
	(*list)->vect.left = NULL;
	first->vect.right = NULL;
	last->vect.right = first;
	first->vect.left = last;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtrotate(&stacka);
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa" -> "miau"