/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 20:00:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtfree(t_mt **mt)
{
	t_mt	*node_to_free;

	if (!mt)
		return ;
	node_to_free = ft_mtdisconnect(mt);
	if (!node_to_free)
		return ;
	if (node_to_free->values.to_free)
	{
		if (node_to_free->free_data)
			node_to_free->free_data(&node_to_free->data);
	}
	if (node_to_free->key)
		free(node_to_free->key);
	free(node_to_free);
}
