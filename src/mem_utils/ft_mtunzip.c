/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtunzip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:02:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 10:33:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtunzip(void **data, size_t size)
{
	t_mt	*list;
	size_t	i;

	if (!data || size == 0)
		return (NULL);
	list = NULL;
	i = 0;
	while (i < size)
	{
		ft_mtpush_data_back(&list, data[i]);
		i++;
	}
	ft_mtpush_data_back(&list, data);
	return (list);
}
