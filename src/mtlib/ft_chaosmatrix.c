/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chaosmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:32:18 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 12:22:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	*check_flag(t_mt **list, t_mt **gc, int flag)
{
	// Acción para mover elementos del list a gc si la bandera es -1
	if (flag == CLEAR)
	{
		if (*list)
			ft_mtmigrate_back(list, gc);
		return (NULL);
	}
	// Devuelve la referencia de la lista si flag es LIST_REF (2)
	else if (flag == LIST_REF)
		return (list);
	// Devuelve el puntero de la lista si flag es LIST_PTR (1)
	else if (flag == LIST_PTR)
		return (*list);
	// Devuelve el puntero del garbage collector si flag es GC_PTR (3)
	else if (flag == GC_PTR)
		return (*gc);
	// Devuelve la referencia del garbage collector si flag es GC_REF (4)
	else if (flag == GC_REF)
		return (gc);
	return (NULL); // Si no es ninguna bandera válida, devuelve NULL
}

// chaosmatrix == cubo de basura
void	*chaosmatrix(int count, size_t size, int flag)
{
	void		*ptr;
	t_mt		*tmp;
	static t_mt	*lst = NULL;
	static t_mt	*gc = NULL;
	void		*result;

	result = check_flag(&lst, &gc, flag);
	if (result)
		return (result);
	if (count == 0 || size == 0)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr)
	{
		ft_memset(ptr, 0, count * size);
		tmp = ft_mtnew(ptr);
		tmp->size = size;
		tmp->count = count;
		return (ft_mtadd_front(&lst, tmp), ptr);
	}
	return (NULL);
}
