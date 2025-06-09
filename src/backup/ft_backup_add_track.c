/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:46:24 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 18:35:46 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"


void	ft_backup_add_track(t_backup **backup, t_track *track)
{
    if (!backup || !*backup || !track)
        return ;
    ft_track_add_back(&(*backup)->tracker, track);
}
