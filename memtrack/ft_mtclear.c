/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:01:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 09:46:21 by danpalac         ###   ########.fr       */
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
			del_func(&(*lst)->data);
		free(*lst);
		(*lst) = NULL;
		*lst = tmp;
	}
	*lst = NULL;
}
void	ft_mterase(t_mt **lst)
{
	if (!lst || !*lst)
		return ;
	while (*lst)
		ft_mtpop(lst);
	*lst = NULL;
}
