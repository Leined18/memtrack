/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace_all_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:01:42 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:27:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces data in all nodes of the list 'lst' with the data 'new_data'.
void	ft_mtreplace_all_data(t_mt **lst, void *new_data, t_data_type type)
{
	t_mt	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		ft_replace(current, new_data, type);
        if (current->children)
            ft_mtreplace_all_data(&current->children, new_data, type);
		current = current->right;
	}
}
