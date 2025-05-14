/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkadd_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:29:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 11:43:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_linkadd_last - Adds a link at the end of the list.
 * @origin: Double pointer to the first link in the list.
 * @link: Pointer to the link to be added.
 *
 * This function adds a new link at the end of the list. If the list is empty,
 * it sets the new link as the first element. If the list is not empty, it
 * traverses to the last link and adds the new link after it.
 */

void	ft_linkadd_last(t_link **origin, t_link *link)
{
	t_link	*last;

	if (!origin || !link)
		return ;
	if (!*origin)
	{
		*origin = link;
		link->prev = NULL;
		return ;
	}
	if ((*origin)->next == NULL)
	{
		(*origin)->next = link;
		link->prev = *origin;
		return ;
	}
	last = *origin;
	while (last->next)
		last = last->next;
	last->next = link;
	link->prev = last;
}