/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:51:53 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/05 12:35:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtpush_data(t_mt **lst, const char *key, void *data,
		t_data_type type)
{
	t_mt	*new;

	if (!data || !lst)
		return ;
	new = ft_mtnew(key, data, type);
	if (!new)
	{
		ft_mtdel_by_type(&data, type);
		return ;
	}
	ft_mtaddlast_left(lst, new);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpush_data(&stacka, ["pi"]);
// stacka = ["pi"] -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
