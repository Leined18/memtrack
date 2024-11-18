/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtunzip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:02:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 13:51:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtunzip(void **data, size_t size)
{
	t_mt	*head;
	size_t	i;

	if (!data || size == 0)
		return (NULL);
	head = NULL;
	i = 0;
	while (i < size)
	{
		ft_mtpush_data_back(&head, data[i]);
		i++;
	}
	return (head);
}
