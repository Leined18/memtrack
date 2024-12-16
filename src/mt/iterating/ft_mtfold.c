/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:19:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 15:24:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtfold(t_mt *lst, int (*func)(t_mt *))
{
	int	result;

	if (!lst || !func || lst->ptr_aux)
		return (0);
	result = 0;
	lst->ptr_aux = "used";
	if (lst->right && !lst->right->ptr_aux)
		result += ft_mtfold(lst->right, func);
	if (lst->left && !lst->left->ptr_aux)
		result += ft_mtfold(lst->left, func);
	if (lst->parent && !lst->parent->ptr_aux)
		result += ft_mtfold(lst->parent, func);
	if (lst->children && !lst->children->ptr_aux)
		result += ft_mtfold(lst->children, func);
	lst->ptr_aux = NULL;
	result += func(lst);
	return (result);
}
