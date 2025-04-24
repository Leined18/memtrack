/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_box_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:06:41 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:16:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"

int	destroy_box_data(t_box **box, void *arg, const char *id)
{
	if (!box || !*box)
		return (0);
	if (ft_strcmp((*box)->id, id) != 0)
		return (0);
	if ((*box)->data)
		free((*box)->data);
	(*box)->data = arg;
	(*box)->size = sizeof(arg);
	return (1);
}
