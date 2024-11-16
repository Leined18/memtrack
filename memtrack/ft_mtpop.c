/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 19:05:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// Deletes the first element of the list.
void	ft_mtpop(t_mt **lst)
{
	t_mt	*tmp;
	t_mt	*gc;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	gc = chaosmatrix(0, 0, 1);
	ft_mtpush_back(&tmp, &gc); // guarda el nodo en el cubo de basura.
}

// Deletes the first element of the list that matches the data with the function cmp.
void	ft_mtpop_cmp(t_mt **lst, void *remove, int (*cmp)(const void *,
			const void *, size_t), size_t n)
{
	t_mt	*current;
	t_mt	*prev;

	if (!lst || !*lst || !remove || !cmp || !n)
		return ;
	current = *lst;
	prev = NULL;
	while (current)
	{
		if (cmp(current->data, remove, n) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			ft_mtpop(&current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpop(&stacka);

// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"

// stacka = "guau" -> "mu" -> ["le"] -> "asd" -> "ñe" -> "sa"
// ft_mtpop_cmp(&stacka, "le", ft_strncmp, 2);
// stacka = "guau" -> "mu" -> "asd" -> "ñe" -> "sa"
