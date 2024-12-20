/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtunzip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:02:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 10:41:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtunzip(void **data, size_t size)
{
	t_mt	*list;
	size_t	i;
	char	*prefix;
	char	*key;

	if (!data || size == 0)
		return (NULL);
	list = NULL;
	i = 0;
	list = ft_mtnew("unzipped", NULL, STRING);
	while (i < size)
	{
		prefix = ft_itoa(i);
		key = ft_strjoin("Data-", prefix);
		ft_mtpush_data_back(&list->children, key, data[i], STRING);
		free(key);
		free(prefix);
		i++;
	}
	free(data);
	return (list);
}
