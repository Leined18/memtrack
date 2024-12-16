/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace_all_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:01:42 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 15:09:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces data in all nodes of the list 'lst' with the data 'new_data'.
void	ft_mtreplace_all_data(t_mt **lst, void *new_data, t_data_type type)
{
	t_mt	*current;

	if (!lst || !*lst || !new_data || !type || (*lst)->ptr_aux)
		return ;
	current = *lst;
	current->ptr_aux = "replaced";
	if (current->right)
		ft_mtreplace_all_data(&current->right, new_data, type);
	if (current->left)
		ft_mtreplace_all_data(&current->left, new_data, type);
	if (current->parent)
		ft_mtreplace_all_data(&current->parent, new_data, type);
	if (current->children)
		ft_mtreplace_all_data(&current->children, new_data, type);
	current->ptr_aux = NULL;
	ft_replace(current, new_data, type);
}
