/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:01:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 18:28:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtclear(t_mt **lst, void (*del_func)())
{
	t_mt	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if (del_func)
			del_func(&(*lst));
		free(*lst);
        (*lst) = NULL;
		*lst = tmp;
	}
	*lst = NULL;
}
