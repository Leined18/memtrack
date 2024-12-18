/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace_all_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:01:42 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 12:04:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtreplace_all_data
 * Replaces data in all nodes of the list 'lst' with the data 'new_data'.
 * @lst: List of nodes to replace the data.
 * @new_data: New data to replace the old data.
 * @type: Type of data to replace.
 * uses ft_replace to replace the data in all nodes of the list
 */

// Replaces data in all nodes of the list 'lst' with the data 'new_data'.

void	ft_replace_match_data(t_mt *mt, void *param)
{
	t_mt	*current;

	current = (t_mt *)param;
	if (mt)
		ft_replace_data(mt, current->data, current->values.data_type);
}

void	ft_mtreplace_all_data(t_mt **lst, void *new_data, t_data_type type)
{
	t_mt	*current;

	if (!lst || !*lst || !new_data)
		return ;
	current = ft_mtnew(NULL, new_data, type);
	ft_mtiter(*lst, current, ft_replace_match_data);
	ft_mtfree(current);
}
