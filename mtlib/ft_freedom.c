/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:31:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 15:37:51 by mvidal-h         ###   ########.fr       */
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