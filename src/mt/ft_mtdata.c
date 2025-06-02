/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:38:42 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 12:01:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	*ft_mtget_data(t_mt *mt)
{
    if (!mt)
        return (NULL);
    return (mt->data);
}

void	(*ft_mtget_data_free(t_mt *mt))(void *)
{
    if (!mt)
        return (NULL);
    return (mt->data_free);
}

void    ft_mtset_data(t_mt *mt, void *data, t_free_func free_func)
{
    if (!mt)
        return;
    
    mt->data = data;
    mt->data_free = free_func;
    if (data && free_func)
        mt->data_free(data);
}

