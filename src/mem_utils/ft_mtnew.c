/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 09:38:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Creates a new node for a list.
t_mt	*ft_mtnew(void *data, ...)
{
	va_list	args;
	t_mt	*new;

	va_start(args, data);
	new = (t_mt *)malloc(sizeof(t_mt));
	if (!new)
		return (NULL);
    ft_memset(new, 0, sizeof(t_mt));
	new->data = data;
	new->size = va_arg(args, size_t);
	new->count = va_arg(args, int);
	va_end(args);
	return (new);
}
