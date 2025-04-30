/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:14:42 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/30 16:11:14 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * @brief rotate the first node to behind the last node of the direction
 *
 *
 */

void	ft_mtrotate(t_mt **lst, t_direction direction)
{
	t_mt	*sub;

	if (!(*lst) || !lst)
		return ;
	sub = NULL;
	sub = ft_mtsub(lst, (*lst));
	if (!sub)
		return ;
	ft_mtaddlast(lst, sub, direction);
}
