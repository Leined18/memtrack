/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 13:14:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// Deletes the first element of the list.
void	ft_mtpop(t_mt **lst)
{
	t_mt	*tmp;
	t_mt	*mem;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	mem = chaosmatrix(0, 0, 1);
	ft_mtadd_back(&mem, ft_mtnew(tmp->data)); // añade data al cubo de basura
	free(tmp); // se libera el nodo
	tmp = NULL; // se pone a NULL
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
