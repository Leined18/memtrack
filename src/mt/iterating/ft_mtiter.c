/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:12:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 15:25:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// aplica la funcion que le envies a cada data de la lista.
void	ft_mtiter(t_mt *lst, void (*func)(t_mt *))
{
	if (!lst || !func || lst->ptr_aux)
		return ;
	lst->ptr_aux = "used";
	func(lst); // Aplica la función al nodo actual
	if (lst->right && !lst->right->ptr_aux)
		ft_mtiter(lst->right, func);
	if (lst->left && !lst->left->ptr_aux)
		ft_mtiter(lst->left, func);
	if (lst->parent && !lst->parent->ptr_aux)
		ft_mtiter(lst->parent, func);
	if (lst->children && !lst->children->ptr_aux)
		ft_mtiter(lst->children, func);
	lst->ptr_aux = NULL; // Restablece al salir
}
