/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_constructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:33:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/20 12:39:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_data_constructor - Constructor de datos genérico.
    * @args: Argumentos para la construcción del objeto.
    * @ap: Lista de argumentos variables.
    * @c_function: Función de construcción.
*/

void *c_data(char *av[], va_list ap)
{
	t_data *data;
	
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	while (*av)
	{
		if (ft_strncmp(*av, "id", 2) == 0)
			data->id = va_arg(ap, int);
		else if (ft_strncmp(*av, "item", 4) == 0)
			data->item = va_arg(ap, void *);
		else if (ft_strncmp(*av, "alloc", 5) == 0)
			data->alloc = va_arg(ap, int);
		else if (ft_strncmp(*av, "size", 4) == 0)
			data->size = va_arg(ap, size_t);
		else if (ft_strncmp(*av, "type", 4) == 0)
			data->type = va_arg(ap, int);
		else if (ft_strncmp(*av, "label", 5) == 0)
			data->label = ft_strdup(va_arg(ap, char *));
		else if (ft_strncmp(*av, "free", 4) == 0)
			data->free = va_arg(ap, void *);
		else
			break ;
		av++;
	}
	return (data);
}
