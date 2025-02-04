/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcheck_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:16:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/04 12:22:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtcheck_key(t_mt *mt, char *key)
{
	if (!mt)
		return (0);
	return (ft_strncmp(mt->key, key, ft_strlen(key)));
}
