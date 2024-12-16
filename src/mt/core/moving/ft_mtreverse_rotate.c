/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:13:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the last element of the list to the first position.
void	ft_mtreverse_rotate(t_mt **list)
{
	t_mt	*last;

	if (!list || !*list || !(*list)->right)
		return ;
	last = *list;
	while (last->right)
		last = last->right;
    last->left->right = NULL;
	last->left = NULL;
	last->right = *list;
	(*list)->left = last;
	*list = last;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtreverse_rotate(&stacka);
// stacka = "sa" -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"
