/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdel_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:10:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 09:30:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	del_array(char **data, size_t size)
{
	size_t	i;

	if (data && *data)
	{
		i = 0;
		while (i < size && data[i])
		{
			free(data[i]);
			data[i] = NULL;
			i++;
		}
		free(data);
		data = NULL;
	}
}

void	ft_mtdel_data(t_mt **list)
{
	char	**tmp;
	int		i;

	if ((*list)->data)
	{
		if ((*list)->size == sizeof(char *))
		{
			tmp = (char **)(*list)->data;
			i = 0;
			while (i < (*list)->count)
			{
				free(tmp[i]);
				tmp[i] = NULL;
				i++;
			}
			if (tmp)
				free(tmp);
			tmp = NULL;
		}
		else
			(free((*list)->data), (*list)->data = NULL);
	}
}
