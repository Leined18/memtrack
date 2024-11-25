/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 18:10:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	ft_mtclear(t_mt **lst)
{
	t_mt	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->free_data)
			tmp->free_data(&tmp->data);
		if (tmp->key)
			free(tmp->key);
		free(tmp);
		tmp = NULL;
	}
	*lst = NULL;
}
