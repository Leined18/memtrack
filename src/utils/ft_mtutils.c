/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:28:54 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 13:46:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_replace(t_mt *current, void *new_data, t_data_type type)
{
	if (!current)
		return ;
	if (current->to_free)
		ft_mtdel_by_type(&current->data, current->type);
	current->data = new_data;
	if (current->type != type)
		current->type = type;
	current->free_data = ft_mtget_free_data(type);
}
