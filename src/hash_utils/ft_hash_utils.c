/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:30:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 20:58:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// obtiene la funcion de eliminacion de datos dependiendo del tipo de dato
void (*ft_mtget_free_data(t_data_type type))(void **)
{
	if (type == BRANCH)
		return (ft_mtdel_list);
	else if (type == LEAF)
		return (ft_mtdel_data);
	else if (type == HASH_TABLE)
		return (ft_mthash_table_free);
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

void	print_hashes_tables(t_hash_table *ht)
{
	t_mt	*list;
	t_mt	*current;

	if (!ht)
		return ;
	list = ft_mthash_collect_types(ht, HASH_TABLE);
	if (!list)
		return ;
	current = list;
	while (list)
	{
		ft_mtprint_hash_table((t_hash_table *)list->data);
		list = list->next;
	}
	ft_mtclear(&current);
}
