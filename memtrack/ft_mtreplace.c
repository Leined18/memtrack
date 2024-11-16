/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:07:31 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:11:28 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces the data 'to_replace' with 'new_data' in the list 'list'.

void	ft_mtreplace(t_mt *list, void *to_replace, void *new_data, int (*cmp)(),
		size_t n)
{
	t_mt	*current;

	if (!list || !cmp)
		return ;
	current = list;
	while (current)
	{
		if (cmp(current->data, to_replace, n) == 0)
		{
			ft_mtdel_data(&current->data);
			current->data = new_data;
		}
		current = current->next;
	}
}

// stacka = "miau" -> "guau" -> ["mu"] -> "le" -> ["mu"] -> "ñe" -> "sa"
// ft_mtreplace(stacka, "mu", "pi", ft_memcmp, 2); // reemplaza "mu" por "pi"
// stacka = "miau" -> "guau" -> ["pi"] -> "le" -> ["pi"] -> "ñe" -> "sa"
