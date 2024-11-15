/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chaosmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:32:18 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 19:18:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// chaosmatrix == cubo de basura
void	*chaosmatrix(int count, size_t size, int flag)
{
	void		*ptr;
	t_mt		*tmp;
	static t_mt	*lst = NULL;
	static t_mt	*gc = NULL;

	if (flag == -1)
	{
		if (lst)
			ft_mtmigrate_back(&lst, &gc);
		return (NULL);
	}
	if (flag)
		return (lst);
	ptr = NULL;
	ptr = malloc(count * size);
	if (ptr)
	{
		ft_memset(ptr, 0, count * size);
		tmp = ft_mtnew(ptr);
		tmp->size = size;
		tmp->count = count;
		ft_mtadd_front(&lst, tmp);
		return (ptr);
	}
	return (NULL);
}
