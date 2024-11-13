/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:31:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 11:18:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	freedom(void **data, t_mt **list)
{
	if (list && *list && data && *data)
	{
		ft_mtremove(list, ft_mtfind_data(*list, *data));
		return ;
	}
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
}