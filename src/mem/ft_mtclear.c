/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 13:47:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/**
 * ft_mtclear - Libera la memoria de la lista.
 * @lst: Lista a liberar.
 * tmp->free_data(&tmp->data); libera segun free_data
 */

static int	ft_mtdel(t_mt *mt)
{
	if (!mt)
		return (0);
	if (mt->values.to_free)
	{
		if (mt->free_data)
			mt->free_data(&mt->data);
	}
	if (mt->key)
		free(mt->key);
	free(mt);
	return (1);
}

int	ft_mtclear(t_mt **lst)
{
	int	result;

	if (!*lst || !lst)
		return (0);
	result = 0;
	result = ft_mtmap(*lst, ft_mtdel);
	*lst = NULL;
	return (result);
}
