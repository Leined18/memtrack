/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:15:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 11:43:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_data_new - Crea una nueva estructura de datos.
 * @data: Puntero a los datos.
 * @size: Tamaño de los datos.
 * @label: Etiqueta de los datos. no se libera.
 * @alloc: Indica si los datos fueron asignados dinámicamente.
 *
 * Retorna una nueva estructura de datos inicializada.
 */

t_data ft_data_new(void *data, size_t size, char *label, bool alloc)
{
	t_data new_data;

	new_data.data = data;
	new_data.size = size;
	new_data.label = label;
	new_data.alloc = alloc;
	new_data.free = NULL;
	return (new_data);
}
