/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace_all_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:01:42 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 13:47:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces data in all nodes of the list 'lst' with the data 'new_data'.
void	ft_mtreplace_all_data(t_mt **lst, void *new_data)
{
	t_mt	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		ft_replace(current, new_data, current->type);
		current = current->next;
	}
}
