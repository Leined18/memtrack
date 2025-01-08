/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtaddlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:35:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/08 09:35:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the end of the list in whatever direction.
void	ft_mtaddlast(t_mt **lst, t_mt *new, t_direction direction)
{
	t_mt	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new->values.data_type = LEAF;
		last = ft_mtlast(*lst, direction);
		ft_mtconnect(last, new, direction);
		ft_mtupdate_cords((*lst), ft_mtcords(0, 0, 0));
		ft_mtconnect_abyacent_cords(last, new);
	}
}
