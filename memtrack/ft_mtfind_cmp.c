/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:11:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 11:17:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

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

