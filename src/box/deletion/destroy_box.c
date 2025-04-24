/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:53:11 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:15:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"

int	destroy_box(t_box **box, void *arg, const char *id)
{
	if (!box || !*box)
		return (0);
	if (ft_strcmp((*box)->id, id) != 0)
		return (0);
	if ((*box)->data)
		(*box)->actions[ORDER_DESTROY_DATA](box, NULL, id);
	if ((*box)->id)
		free((*box)->id);
	free(*box);
	*box = arg;
	return (1);
}
