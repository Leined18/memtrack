/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtaddon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:40:21 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 21:57:11 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	*ft_mtget_addon(t_mt *mt)
{
    if (!mt)
        return (NULL);
    return (mt->addon);
}

void	(*ft_mtget_addon_free(t_mt *mt))(void *)
{
    if (!mt)
        return (NULL);
    return (mt->addon_free);
}

void	ft_mtset_addon(t_mt *mt, void *addon, t_freec_func freec_func)
{
    if (!mt)
        return;
    if (mt->addon && mt->addon_free)
        mt->addon_free(mt->addon);
    mt->addon = addon;
    mt->addon_free = freec_func;
}
