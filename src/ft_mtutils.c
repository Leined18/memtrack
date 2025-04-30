/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:28:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/30 15:42:29 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_replace_data(t_mt *current, void *new_data, t_data_type type)
{
	if (!current)
		return ;
	if (current->values.to_free)
		ft_mtdel_by_type(&current->data, current->values.data_type);
	current->data = new_data;
	current->values.data_type = type;
	current->free_data = ft_mtget_free_data(type);
}

void	ft_replace_key(t_mt *current, char *new_key)
{
	if (!current || !new_key)
		return ;
	if (current->key)
		free(current->key);
	current->key = ft_strdup(new_key);
}

t_free_funtion	ft_mtget_free_data(t_data_type type)
{
	if (type == NONE)
		return (NULL);
	else if (type == LIST)
		return (ft_mtdel_list);
	else if (type == STRING)
		return (free_null);
	else if (type == PTR)
		return (free_null);
	return (NULL);
}

void	ft_mtdel_by_type(void **data, t_data_type type)
{
	void	(*del_function)(void **);

	if (!data || !*data)
		return ;
	del_function = ft_mtget_free_data(type);
	if (del_function)
		del_function(data);
}
