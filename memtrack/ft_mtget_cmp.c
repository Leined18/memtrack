/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtget_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:51:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:10:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// devuelve un nodo que busque en la lista y lo aisla de la lista original. lo saca de la lista.
t_mt	*ft_mtget_cmp(t_mt **lst, void *data, int (*cmp)(), size_t n)
{
	t_mt	*prev;
	t_mt	*current;

	prev = NULL;
	if (!lst || !*lst || !cmp || !n)
		return (NULL);
	current = *lst;
	while (current)
	{
		if (cmp(current->data, data, n) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			current->next = NULL;
			return (current);
		}
		prev = current;
		current = current->next;
	}
	return (NULL);
}
// path = ft_strdup("HOME/../../");
// lista1 = "miau" -> "guau" -> "mu" -> ["HOME/../../"] -> "asd" -> "ñe" -> "sa"
// lista2 = ft_mtget_cmp(&lista1, path, ft_strcmp, ft_strlen(path));
// lista2 = ["HOME/../../"];
// lista1 = "miau" -> "guau" -> "mu" -> "asd" -> "ñe" -> "sa"
