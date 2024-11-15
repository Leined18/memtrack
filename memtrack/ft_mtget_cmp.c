/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtget_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:51:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 10:52:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

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
