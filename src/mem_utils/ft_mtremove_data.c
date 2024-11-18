/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 09:59:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// busca el nodo que buscas en la lista y elimina la data no el nodo.
void	ft_mtremove_data(t_mt **lst, void *data, int (*cmp)(), size_t n)
{
	t_mt	*current;

	current = *lst;
	while (current)
	{
		if (!cmp(current->data, data, n))
			ft_mtdel_data(&current->data);
		current = current->next;
	}
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtremove(&stacka, "le", ft_strncmp, 2);
// stacka = "miau" -> "guau" -> "mu" -> (NULL) -> "asd" -> "ñe" -> "sa"
