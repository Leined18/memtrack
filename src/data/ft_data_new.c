/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:35:13 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 10:07:28 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
* ft_data_new - Crea una nueva estructura de datos.
* @item: Puntero a los datos.
* @size: Tamaño de los datos.
* @free: Función de liberación de memoria.
*
*/
 
t_data *ft_data_new(void *item, size_t size, void (*free)(void *))
{
    t_data	*new_data;

    new_data = constructor(c_data, "%id%item%alloc%size%type%label%free",
    0, item, true, size, 0, NULL, free);
    return (new_data);
}
