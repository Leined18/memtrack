/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtgroup_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:36:48 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 18:04:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char	*ft_mtget_group_id(t_mt *mt)
{
    if (!mt)
        return (NULL);
    return (mt->group_id);
}

void	ft_mtset_group_id(t_mt *mt, void *group_id)
{
    if (!mt || !group_id)
        return;
    
    if (mt->group_id)
        free(mt->group_id);
    mt->group_id = ft_strdup(group_id);
}

int     ft_mtgroup_id_cmp(const t_mt *mt1, const char *group_id)
{
    if (!mt1 || !mt1->group_id || !group_id)
        return (0);
    return (ft_strncmp(mt1->group_id, group_id, ft_strlen(mt1->group_id)) == 0);
}