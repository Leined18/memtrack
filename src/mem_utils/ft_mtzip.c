/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtzip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:30:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 13:50:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtzip(t_mt **lst)
{
	t_mt	*new;
	t_mt	*tmp;
	void	**datas;
	size_t	size;
	size_t	i;

	if (!lst || !*lst)
		return (NULL);
	size = ft_mtsize(*lst);
	if (size == 0)
		return (NULL);
	datas = ft_calloc(size + 1, sizeof(void *));
	if (!datas)
		return (NULL);
	tmp = *lst;
	i = 0;
	while (tmp)
	{
		datas[i++] = tmp->data;
		tmp = tmp->next;
	}
	datas[i] = NULL;
	(ft_mterase(lst), new = ft_mtnew_chaos(datas));
	new->count = size;
	return (new);
}
