/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtkey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:36:48 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/04 00:35:58 by daniel           ###   ########.fr       */
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
        freec(mt->key);
    mt->key = ft_strdup(key);
}

int     ft_mtkeycmp(const t_mt *mt1, const char *key)
{
    if (!mt1 || !mt1->key || !key)
        return (0);
    return (ft_strncmp(mt1->key, key, ft_strlen(mt1->key)) == 0);
}