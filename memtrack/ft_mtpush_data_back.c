/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_data_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:13:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:10:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'data' at the end of the list.
void	ft_mtpush_data_back(t_mt **lst, void *data)
{
	t_mt	*new;

	if (!data || !lst)
		return ;
	new = chaosmatrix(1, sizeof(t_mt), 0);
	new->data = data;
	new->size = sizeof(t_mt);
	new->count = 1;
	new->next = NULL;
	ft_mtadd_back(lst, new);
}
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpush_data_back(&stacka, "pi");
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa" -> "pi"
