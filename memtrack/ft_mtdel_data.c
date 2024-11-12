/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdel_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:10:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/12 17:31:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void   del_array(char **data, size_t size)
{
    size_t  i;
    
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

void    del_by_type(void **data, size_t size)
{
    if (size == sizeof(int))
    {
        free(*data);
        *data = NULL;
    }
    else if (size == sizeof(char *))
    {
        del_array((char **)data, size);
    }
}

void	ft_mtdel_data(void **data, size_t size)
{
    (void)size;
	if (data && *data)
	{
        if (size > 1)
            del_by_type((void **)*data, size);
		free(*data);
		*data = NULL;
	}
}
