/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_box_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:04:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 22:57:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

int	get_box_builder(t_builder **builder, t_box **box, void *arg, const char *id)
{
	if (!builder || !*builder)
		return (0);
	if (!(*builder)->box)
	{
		*box = NULL;
		return (0);
	}
	if (box && *box)
	{
		(*box)->destroy(*box);
		*box = NULL;
	}
	if ((*builder)->box)
	{
		*box = (*builder)->box;
		return (1);
	}
	return (0);
}
