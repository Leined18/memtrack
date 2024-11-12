/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:01:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/12 14:58:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtclear(t_mt **lst, void (*del_func)())
{
	t_mt *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		if (del_func)
			del_func((*lst)->data, (*lst)->size);
		free(*lst);
		*lst = tmp;
	}
    *lst = NULL;
}
