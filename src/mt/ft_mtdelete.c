/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdelete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:02:46 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 15:23:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtdelete(const char *key)
{
    t_mt *target;
    t_backup *backup;
    
    if (!key || ft_strlen(key) == 0)
        return ;
    backup = ft_backup_static(0, false, false); // Obtiene el backup estático
    target = ft_backup_get(backup, key);
    ft_backup_remove(&backup, target, true);
}