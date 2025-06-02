/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:01:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 15:16:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtget(t_mt *mt, const char *key)
{
    if (!mt || !key || ft_strlen(key) == 0)
        return (NULL);
    if (ft_strncmp(mt->key, key, ft_strlen(key)) == 0)
        return (mt);
    while (mt->next)
    {
        mt = mt->next;
        if (ft_strncmp(mt->key, key, ft_strlen(key)) == 0)
            return (mt);
    }
    return (NULL);
}