/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:11:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:09:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Finds the first element in the list that matches the data with the function cmp.
// mt = ft_mtfind_cmp(stacka, "le", ft_strncmp, 2);
// mt->data == "le"; -> es para ver o cambiar data de un nodo especifico.
t_mt	*ft_mtfind_cmp(t_mt *lst, void *data, int (*cmp)(), size_t n)
{
	t_mt	*current;

	if (!lst || !cmp || !n)
		return (NULL);
	current = lst;
	while (current)
	{
		if (cmp(current->data, data, n) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
// stacka = "miau" -> "guau" -> "mu" -> ["le"] -> "asd" -> "ñe" -> "sa"
// mt = ft_mtfind_cmp_ref(&stacka, "le", ft_strncmp, 2);
// ft_mterase(&mt); se elimina a partir de "le" hasta el final.
// stacka = "miau" -> "guau" -> "mu"
t_mt	**ft_mtfind_cmp_ref(t_mt **lst, void *data, int (*cmp)(), size_t n)
{
	t_mt	*current;

	if (!lst || !*lst || !cmp || !n)
		return (NULL);
	current = *lst;
	while (current)
	{
		if (cmp(current->data, data, n) == 0)
			return (lst); // Devuelve un puntero doble al nodo encontrado.
		lst = &current->next;
		current = current->next;
	}
	return (NULL);
}
