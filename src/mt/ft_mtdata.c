/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:38:42 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 21:57:26 by daniel           ###   ########.fr       */
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

void    ft_mtset_data(t_mt *mt, void *data, t_freec_func freec_func)
{
    if (!mt)
        return;
    
    mt->data = data;
    mt->data_free = freec_func;
    if (data && freec_func)
        mt->data_free(data);
}

