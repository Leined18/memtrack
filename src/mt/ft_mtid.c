/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:36:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 11:44:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtget_id(t_mt *mt)
{
    if (!mt)
        return (-1);
    return (mt->id);
}

void	ft_mtset_id(t_mt *mt, int id)
{
    if (!mt)
        return;
    mt->id = id;
}


