/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:10:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

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
