/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:16:13 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 17:44:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// Adds the element 'new' at the beginning of the list.

void	ft_mtadd_front(t_mt **lst, t_mt *new)
{
    new->next = *lst;
    *lst = new;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
}
