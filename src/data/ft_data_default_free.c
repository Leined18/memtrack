/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_default_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:16:22 by danpalac         ###   ########.fr       */
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

void ft_data_def_free(t_data *data)
{
	if (data->alloc && data->item)
		free_null(&data->item);
	data->item = NULL;
	data->size = 0;
	data->label = NULL;
	data->alloc = false;
}
