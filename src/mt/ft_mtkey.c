/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtkey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:36:48 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 11:57:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char	*ft_mtget_key(t_mt *mt)
{
    if (!mt)
        return (NULL);
    return (mt->key);
}

void	ft_mtset_key(t_mt *mt, const char *key)
{
    if (!mt || !key)
        return;
    
    if (mt->key)
        free(mt->key);
    mt->key = ft_strdup(key);
}

