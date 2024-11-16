/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:01:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:14:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Deletes and frees the memory of the elements of the list. with the funtion del_func.
// delete all the elements of the list. not in chaosmatrix. (data-> chaosmatrix.)
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

// chaosmatrix == cubo de basura
// Deletes all nodes of the list.
void	ft_mterase(t_mt **lst)
{
	if (!lst || !*lst)
		return ;
	while (*lst)
		ft_mtpop(lst); // borra el primer nodo de la lista.
	*lst = NULL;
}
