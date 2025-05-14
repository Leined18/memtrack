/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:51:41 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 12:20:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtclear_link(t_link **links)
{
	t_link	*link;
	t_link 	*temp;

	if (!links || !*links)
		return ;
	link = *links;
	if (link->next)
	{
		temp = link->next;
		link->next = NULL;
		temp->prev = NULL;
		ft_mtclear_link(&temp);
	}
	if (link->prev)
	{
		temp = link->prev;
		link->prev = NULL;
		temp->next = NULL;
		ft_mtclear_link(&temp);
	}
	free(link);
	*links = NULL;
}
