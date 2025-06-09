/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:23:39 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 16:13:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_hash_str - Calcula el hash de una cadena.
 * @str: Cadena a hashear.
 * 
 */

size_t    ft_hash_str(const char *str)
{
    size_t	hash;
    size_t	i;

    if (!str)
        return (0);
    hash = 0;
    i = 0;
    while (str[i])
    {
        hash += str[i];
        i++;
    }
    return (hash);
}


/**
 * ft_backup_search - Obtiene un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @key: Clave del nodo a buscar.
 * 
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_track *ft_backup_search(t_backup *backup, const char *key)
{
	t_track *found;
    
	if (!backup || !key)
		return (NULL);
	found = ft_track_search(backup->tracker, key);
    if (!found)
    {
        found = ft_slot_search(backup->slots, backup->slot_count, key);
        if (!found)
            return (NULL); // Retorna NULL si no se encuentra el nodo
    }
	return (found);
}