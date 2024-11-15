/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:31:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 07:55:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	freedom(void **data, t_mt **list)
{
	if (list && *list && data && *data)
	{
		free(*data);
		*data = NULL;
		ft_mtpop(list);
		return ;
	}
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
}
