/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:02 by danpalac         ###   ########.fr       */
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
	*lst = (*lst)->vect[RIGHT];
	if (*lst)
		(*lst)->vect[LEFT] = NULL;
	tmp->vect[RIGHT] = NULL;
	ft_mtdelete(&tmp);
}
