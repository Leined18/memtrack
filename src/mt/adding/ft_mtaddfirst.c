/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtaddfirst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:37:08 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/05 19:24:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtaddfirst(t_mt **lst, t_mt *new, t_direction direction)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ft_mtconnect_safe(lst, new, direction);
		ft_mtupdate_cords((*lst), (*lst)->cords);
		(*lst) = new;
	}
}
