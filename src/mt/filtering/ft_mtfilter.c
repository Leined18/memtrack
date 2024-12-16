/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfilter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 15:28:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	**ft_mtfilter(t_mt *lst, int (*predicate)(t_mt *), t_mt **result,
		int *size)
{
	if (!lst || !predicate || lst->ptr_aux)
		return (result);
	lst->ptr_aux = "used";
	if (predicate(lst))
	{
		result[*size] = lst; // Agrega el nodo al resultado
		(*size)++;
	}
	if (lst->right && !lst->right->ptr_aux)
		result = ft_mtfilter(lst->right, predicate, result, size);
	if (lst->left && !lst->left->ptr_aux)
		result = ft_mtfilter(lst->left, predicate, result, size);
	if (lst->parent && !lst->parent->ptr_aux)
		result = ft_mtfilter(lst->parent, predicate, result, size);
	if (lst->children && !lst->children->ptr_aux)
		result = ft_mtfilter(lst->children, predicate, result, size);
	lst->ptr_aux = NULL; // Restablece al salir
	return (result);
}
