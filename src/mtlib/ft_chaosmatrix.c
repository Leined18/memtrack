/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chaosmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:32:18 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:48:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	*chaosmatrix(int count, size_t size, int flag)
{
	void		*ptr;
	t_mt		*tmp;
	static t_mt	*gc = NULL;

	if (flag == CLEAR)
	{
		ft_mtclear(&gc);
		return (NULL);
	}
	if (flag == GC_PTR)
		return (gc);
	if (flag == GC_REF)
		return (&gc);
	if (count == 0 || size == 0)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr)
	{
		ft_memset(ptr, 0, count * size);
		tmp = ft_mtnew("", ptr, NONE);
		return (ft_mtadd_front(&gc, tmp), ptr);
	}
	return (NULL);
}
