/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chaosmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:32:18 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 13:26:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// chaosmatrix == cubo de basura
void	*chaosmatrix(int count, size_t size, int flag)
{
	void		*ptr;
	t_mt		*tmp;
	static t_mt	*list = NULL;

	if (flag == -1)
		return (ft_mtclear(&list, ft_mtdel_data), NULL);
	if (flag)
		return (list);
	ptr = NULL;
	ptr = malloc(count * size);
	if (ptr)
	{
		ft_memset(ptr, 0, count * size);
		tmp = ft_mtnew(ptr);
		tmp->size = size;
		tmp->count = count;
		ft_mtadd_front(&list, tmp);
		return (ptr);
	}
	return (NULL);
}
