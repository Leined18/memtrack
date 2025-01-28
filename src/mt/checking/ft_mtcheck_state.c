/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcheck_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:05:11 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/28 11:06:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtcheck_state(t_mt *mt, int state)
{
	if (!mt)
		return (0);
	if (mt->values.state == state)
		return (1);
	return (0);
}
