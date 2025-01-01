/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the first element of the list to the last position.
void	ft_mtrotate(t_mt **list)
{
	t_mt	*first;
	t_mt	*last;

	if (!list || !*list || !(*list)->vect[RIGHT])
		return ;
	first = *list;
	last = *list;
	while (last->vect[RIGHT])
		last = last->vect[RIGHT];
	*list = first->vect[RIGHT];
	(*list)->vect[LEFT] = NULL;
	first->vect[RIGHT] = NULL;
	last->vect[RIGHT] = first;
	first->vect[LEFT] = last;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtrotate(&stacka);
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa" -> "miau"