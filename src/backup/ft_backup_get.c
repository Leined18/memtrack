/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:23:39 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/04 00:02:29 by daniel           ###   ########.fr       */
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
 * ft_backup_get - Obtiene un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @key: Clave del nodo a buscar.
 * 
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_mt	*ft_backup_get(t_backup *backup, const char *key)
{
	size_t	index;
	t_mt	*cur;
	t_mt 	*found;
	t_track *track;

	if (!backup || !key)
		return (NULL);
	cur = NULL;
	index = ft_hash_str(key) % backup->slot_count;
	if (backup->slots)
		cur = backup->slots[index];
	found = ft_mtget(cur, key);
	if (!found)
	{
		track = ft_backup_get_track(backup->tracker, key);
		if (track)
			found = track->node;
	}
	return (found);
}