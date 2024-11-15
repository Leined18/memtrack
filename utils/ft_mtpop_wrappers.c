/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop_wrappers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:54:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 10:02:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtpop_string(t_mt **lst, char *remove, size_t n)
{
	ft_mtpop_cmp(lst, remove, (int (*)(const void *, const void *,
				size_t))ft_strncmp, n);
}

void	ft_mtpop_number(t_mt **lst, int remove)
{
	t_mt	*current;
	t_mt	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (current->n == remove)
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

void	ft_mtpop_data(t_mt **lst, const void *remove, size_t size)
{
	ft_mtpop_cmp(lst, remove, (int (*)(const void *, const void *))ft_memncmp, size);
}
