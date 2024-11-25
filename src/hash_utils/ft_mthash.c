/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:20:36 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 13:31:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

size_t	ft_mthash(const char *key, size_t bucket_count)
{
	size_t hash;

	hash = 0;
	while (*key)
		hash = (hash * 31) + *(key++);
	return (hash % bucket_count);
}
