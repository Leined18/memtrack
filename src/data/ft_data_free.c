/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/20 12:44:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_data_def_free - Libera la memoria de los datos.
 * @data: Doble puntero a la estructura de datos.
 *
 * Esta función libera la memoria ocupada por los datos y restablece los
 * valores de la estructura de datos a su estado inicial.
 */

void ft_data_free(void *ptr)
{
	t_data *data;

	if (!ptr)
		return ;
	data = (t_data *)ptr;
	if (data->alloc && data->item)
		data->free(data->item);
	if (data->label)
		free(data->label);
	free(data);
}
