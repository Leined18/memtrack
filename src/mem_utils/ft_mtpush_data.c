/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:51:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 08:10:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtpush_data(t_mt **lst, void *data)
{
	t_mt	*new;

	if (!data || !lst)
		return ;
	new = chaosmatrix(1, sizeof(t_mt), 0);
	new->data = data;
	new->size = sizeof(t_mt);
	new->count = 1;
	new->next = NULL;
    new->prev = NULL;
	ft_mtadd_front(lst, new);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpush_data(&stacka, ["pi"]);
// stacka = ["pi"] -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
