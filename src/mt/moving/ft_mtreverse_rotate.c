/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the last element of the list to the first position.
void	ft_mtreverse_rotate(t_mt **list)
{
	t_mt	*last;

	if (!list || !*list || !(*list)->vect[RIGHT])
		return ;
	last = *list;
	while (last->vect[RIGHT])
		last = last->vect[RIGHT];
	last->vect[LEFT]->vect[RIGHT] = NULL;
	last->vect[LEFT] = NULL;
	last->vect[RIGHT] = *list;
	(*list)->vect[LEFT] = last;
	*list = last;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtreverse_rotate(&stacka);
// stacka = "sa" -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"
