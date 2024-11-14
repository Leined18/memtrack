/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:51:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 10:26:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtpush_data(t_mt **lst, void *data)
{
	t_mt *new;

	if (!data || !lst)
		return ;
	new = chaosmatrix(1, sizeof(t_mt), 0);
	new->data = data;
	new->size = sizeof(t_mt);
	new->count = 1;
	ft_mtadd_back(lst, new);
}
