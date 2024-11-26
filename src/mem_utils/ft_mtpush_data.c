/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:51:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 09:48:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtpush_data(t_mt **lst, const char *key ,void *data)
{
	t_mt	*new;

	if (!data || !lst)
		return ;
	new = ft_mtnew(key, data, LEAF);
	ft_mtadd_front(lst, new);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpush_data(&stacka, ["pi"]);
// stacka = ["pi"] -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
