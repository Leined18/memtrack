/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 13:11:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// Creates a new node for a list.
t_mt	*ft_mtnew(void *data)
{
	t_mt	*new;

	new = (t_mt *)malloc(sizeof(t_mt));
	if (!new)
		return (NULL);
	new->data = data;
	new->size = 0;
    new->count = 0;
	new->n = 0;
	new->next = NULL;
	return (new);
}
