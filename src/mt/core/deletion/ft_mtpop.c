/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:54:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Deletes the first element of the list.
void	ft_mtpop(t_mt **lst)
{
	t_mt	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->vect.right;
	if (*lst)
		(*lst)->vect.left = NULL;
	tmp->vect.right = NULL;
	ft_mtfree(tmp);
}
