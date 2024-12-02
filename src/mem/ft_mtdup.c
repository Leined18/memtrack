/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:51:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:22:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtdup(t_mt *src)
{
	t_mt	*dst;

	if (!src)
		return (NULL);
	dst = ft_mtnew(src->key, NULL, src->values.data_type);
	if (!dst)
		return (NULL);
	if (src->values.data_type != STRING)
	{
		dst->data = src->data;
		dst->values.to_free = 0;
		dst->values.size = src->values.size;
		dst->values.count = src->values.count;
		dst->free_data = src->free_data;
        dst->values.node_type = src->values.node_type;
		return (dst);
	}
	dst->data = ft_strdup(src->data);
	return (dst);
}
