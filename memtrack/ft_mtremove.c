/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:11:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// busca el nodo que buscas en la lista y elimina la data no el nodo.
void	ft_mtremove(t_mt **lst, void *data, int *(cmp)(), size_t n)
{
	t_mt	*current;
	t_mt	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (!cmp(current->data, data, n))
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			ft_mtdel_data(&current->data);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtremove(&stacka, "le", ft_strncmp, 2);
// stacka = "miau" -> "guau" -> "mu" -> (NULL) -> "asd" -> "ñe" -> "sa"
