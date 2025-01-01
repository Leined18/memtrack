/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:09:27 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 08:44:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static int	match_node(t_mt *node, void *sub)
{
	return (node == sub);
}

t_mt	*ft_mtsub(t_mt **mt, t_mt *node_to_sub)
{
	t_mt	*sub;

	if (!mt || !*mt || !node_to_sub)
		return (NULL);
	sub = ft_mtsearch(*mt, node_to_sub, match_node);
	if (sub == NULL)
		return (NULL);
	sub = ft_mtdisconnect_safe(mt, sub);
	if (sub)
		return (sub);
	return (NULL);
}
