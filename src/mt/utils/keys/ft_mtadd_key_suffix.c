/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_key_suffix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:48:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 14:48:28 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtadd_key_suffix(char *suffix, t_mt *node)
{
	char *new_key;

	if (!suffix || !node)
		return ;
	new_key = ft_strjoin(node->key, suffix);
	free(node->key);
	node->key = new_key;
}
