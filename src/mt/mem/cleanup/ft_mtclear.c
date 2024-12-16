/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 14:54:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/**
 * ft_mtclear - Libera la memoria de la lista.
 * @lst: Lista a liberar.
 * tmp->free_data(&tmp->data); libera segun free_data
 */

void	ft_mtclear(t_mt **lst)
{
	if (!*lst || !lst || (*lst)->ptr_aux)
		return ;
	(*lst)->ptr_aux = "freed";
	if ((*lst)->parent)
		ft_mtclear(&(*lst)->parent);
	if ((*lst)->right)
		ft_mtclear(&(*lst)->right);
	if ((*lst)->left)
		ft_mtclear(&(*lst)->left);
	if ((*lst)->children)
		ft_mtclear(&(*lst)->children);
	if (*lst)
	{
		if ((*lst)->values.to_free)
		{
			if ((*lst)->free_data && (*lst)->data)
				(*lst)->free_data(&(*lst)->data);
		}
		if ((*lst)->key)
			free((*lst)->key);
		free_null((void **)lst);
	}
}
