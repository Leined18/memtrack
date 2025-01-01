/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconnect_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 01:03:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_connect_nodes(t_mt *node1, int direction1, t_mt *node2,
		int direction2)
{
	if (node1 && node2)
	{
		node1->vect[direction1] = node2;
		node2->vect[direction2] = node1;
	}
}
