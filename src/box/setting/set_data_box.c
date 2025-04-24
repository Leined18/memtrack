/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:40:14 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:16:07 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"

int	set_data_box(t_box **box, void *data, const char *id)
{
	if (!box || !*box)
		return (0);
	if (data && ft_strcmp((*box)->id, id) == 0)
	{
		if ((*box)->actions[ORDER_DESTROY_DATA])
			(*box)->actions[ORDER_DESTROY_DATA](box, data, id);
		(*box)->data = data;
		(*box)->size = sizeof(data);
	}
	return (1);
}
