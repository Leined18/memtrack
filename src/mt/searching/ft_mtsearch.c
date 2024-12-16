/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 17:22:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtsearch(t_mt *lst, void *param, int (*predicate)(t_mt *, void *))
{
	t_mt	*found;

	if (!lst || !predicate || lst->ptr_aux)
		return (NULL);
	lst->ptr_aux = "used";
	if (predicate(lst, param)) // Si el nodo cumple la condición, lo devolvemos
	{
		lst->ptr_aux = NULL;
		return (lst);
	}
	found = NULL;
	if (lst->right && !lst->right->ptr_aux)
		found = ft_mtsearch(lst->right, param, predicate);
	if (!found && lst->left && !lst->left->ptr_aux)
		found = ft_mtsearch(lst->left, param, predicate);
	if (!found && lst->parent && !lst->parent->ptr_aux)
		found = ft_mtsearch(lst->parent, param, predicate);
	if (!found && lst->children && !lst->children->ptr_aux)
		found = ft_mtsearch(lst->children, param, predicate);
	lst->ptr_aux = NULL; // Restablece al salir
	return (found);
}
