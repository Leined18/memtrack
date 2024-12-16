/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:00:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the first element of the list to the last position.
void	ft_mtrotate(t_mt **list)
{
	t_mt	*first;
	t_mt	*last;

	if (!list || !*list || !(*list)->right)
		return ;
	first = *list;
	last = *list;
	while (last->right)
		last = last->right;
	*list = first->right;
    (*list)->left = NULL;
	first->right = NULL;
	last->right = first;
    first->left = last;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtrotate(&stacka);
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa" -> "miau"