/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtmigrate_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:01:18 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 15:06:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtmigrate_back(t_mt **src, t_mt **dest)
{
	while (*src)
		ft_mtpush_back(src, dest);
}
