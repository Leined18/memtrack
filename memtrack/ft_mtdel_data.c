/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdel_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:10:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 12:58:14 by danpalac         ###   ########.fr       */
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
// Deletes the data of the element of the list.
void	ft_mtdel_data(void **data)
{
    t_mt *gc;
    
	if (data && *data)
    {
        gc = chaosmatrix(0, 0, 1);
        ft_mtadd_back(&gc, ft_mtnew(*data));
        *data = NULL;
    }
}

/* mt->data = ft_strdup("miau");

ft_mtdel_data(&data);
mt->data == NULL;
mt->data = ft_strdup("guau"); */