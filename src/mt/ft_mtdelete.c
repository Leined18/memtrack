/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdelete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 10:59:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtdelete(void *mt)
{
	t_mt *node;
	
	if (!mt)
		return ;
	node = (t_mt *)mt;
	if (node->key)
		free(node->key);
	if (node->data.free)
		node->data.free(&node->data);
	if (node->links)
		ft_mtclear_link(&node->links);
	if (node->aux)
		ft_mtclear(&node->aux);
	free(mt);
}
