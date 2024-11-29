/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:30:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 14:41:02 by danpalac         ###   ########.fr       */
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
