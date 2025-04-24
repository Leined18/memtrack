/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_box_builder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:08:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 18:08:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

int	set_box_builder(t_builder *builder, t_box *box)
{
	if (!builder || !box)
		return (0);
	if (builder->box)
	{
		builder->box->destroy(builder->box);
		builder->box = NULL;
	}
	builder->box = box;
	return (1);
}
