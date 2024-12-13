/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:31:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 13:39:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtmap(t_mt *lst, int (*func)(t_mt *))
{
	int	result;

	if (!lst || !func || lst->ptr_aux)
		return (0);
	result = 0;
	lst->ptr_aux = "used";
	if (lst->parent)
		result += ft_mtmap(lst->parent, func);
	if (lst->right)
		result += ft_mtmap(lst->right, func);
	if (lst->left)
		result += ft_mtmap(lst->left, func);
	if (lst->children)
		result += ft_mtmap(lst->children, func);
	lst->ptr_aux = NULL;
	result += func(lst);
	return (result);
}

int	ft_mtbool(t_mt *node)
{
	if (!node)
		return (0);
	ft_mtprint(node);
	return (1);
}