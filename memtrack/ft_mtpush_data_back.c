/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_data_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:13:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 15:14:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtpush_data_back(t_mt **lst, void *data)
{
	t_mt	*new;

	if (!data || !lst)
		return ;
	new = chaosmatrix(1, sizeof(t_mt), 0);
	new->data = data;
	new->size = sizeof(t_mt);
	new->count = 1;
	ft_mtadd_back(lst, new);
}
