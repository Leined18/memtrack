/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:20:36 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 13:19:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

// hash function for the hash table
// returns the hash of the key
size_t	ft_mthash(const char *key, size_t bucket_count)
{
	size_t hash;

	hash = 0;
	while (*key)
		hash = (hash * 31) + *(key++);
	return (hash % bucket_count);
}

// string "hola" -> hash 1234
