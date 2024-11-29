/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:51:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 15:12:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtdup(t_mt *src)
{
	t_mt *dst;

	if (!src)
		return (NULL);
	dst = ft_mtnew(src->key, NULL, src->type);
	if (!dst)
		return (NULL);
	if (src->type != LEAF)
	{
		dst->data = src->data;
		dst->to_free = 0;
		return (dst);
	}
	dst->data = ft_strdup(src->data);
	return (dst);
}
