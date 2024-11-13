/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:31:49 by danpalac          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/13 14:41:21 by danpalac         ###   ########.fr       */
=======
/*   Updated: 2024/11/13 11:18:45 by danpalac         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
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
<<<<<<< HEAD
	else if (data && *data)
=======
	if (data && *data)
>>>>>>> refs/remotes/origin/main
	{
		free(*data);
		*data = NULL;
	}
}