/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:19:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 18:20:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtsize(t_mt *node)
{
	int	size;

	size = 0;
	if (!node)
		return (0);
	size = 1;
	for (int i = 0; i < MAX_DIRECTIONS; i++)
		size += ft_mtsize(node->vect[i]);
	return (size);
}
