/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:23:39 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 12:19:44 by danpalac         ###   ########.fr       */
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

	if (!backup || !backup->slots || !key)
		return (NULL);

	index = ft_hash_str(key) % backup->slot_count;
	cur = backup->slots[index];
	while (cur)
	{
		if (cur->key && ft_strncmp(cur->key, key, ft_strlen(key)) == 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}