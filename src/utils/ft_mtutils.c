/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:28:54 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 12:10:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_replace(t_mt *current, void *new_data, t_data_type type)
{
	if (!current)
		return ;
	if (current->values.to_free)
		ft_mtdel_by_type(&current->data, current->values.data_type);
	current->data = new_data;
	if (current->values.data_type != type)
		current->values.data_type = type;
	current->free_data = ft_mtget_free_data(type);
}
