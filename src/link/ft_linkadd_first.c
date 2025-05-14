/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkadd_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:20:20 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 17:20:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_linkadd_first - Adds a link at the beginning of the list.
 * @origin: Double pointer to the first link in the list.
 * @link: Pointer to the link to be added.
 *
 * This function adds a new link at the beginning of the list. If the list is empty,
 * it sets the new link as the first element. If the list is not empty, it adds
 * the new link before the current first link.
 */

void	ft_linkadd_first(t_link **origin, t_link *link)
{
	t_link	*first;

	if (!origin || !link)
		return ;
	if (!*origin)
	{
		*origin = link;
		link->prev = NULL;
		return ;
	}
	first = *origin;
	first->prev = link;
	link->next = first;
	link->prev = NULL;
	*origin = link;
}
