/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:28:54 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/10 12:27:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_replace(t_mt *current, void *new_data, t_data_type type)
{
	if (!current)
		return ;
	if (current->values.to_free)
		ft_mtdel_by_type(&current->data, current->values.data_type);
	current->data = new_data;
	if (current->values.data_type != (int)type)
		current->values.data_type = type;
	current->free_data = ft_mtget_free_data(type);
}

// obtiene la funcion de eliminacion de datos dependiendo del tipo de dato
void (*ft_mtget_free_data(t_data_type type))(void **)
{
	if (type == NONE)
		return (NULL);
	else if (type == LIST)
		return (ft_mtdel_list);
	else if (type == STRING)
		return (ft_mtdel_data);
	else if (type == HASH_TABLE)
		return (ft_mthash_table_free);
	else if (type == PTR)
		return (ft_mtdel_data);
	return (NULL);
}

// elimina un dato dependiendo del tipo de dato
void	ft_mtdel_by_type(void **data, t_data_type type)
{
	void	(*del_function)(void **);

	if (!data || !*data)
		return ;
	del_function = ft_mtget_free_data(type);
	if (del_function)
		del_function(data);
}
