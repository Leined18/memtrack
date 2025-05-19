/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:38:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 12:06:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_clear - Libera la memoria de la estructura de backup.
 * @backup: Doble puntero a la estructura de backup.
 *
 * Esta función libera la memoria ocupada por la estructura de backup y sus
 * elementos. Se asegura de liberar todos los slots y el tracker asociado.
 */

void	ft_backup_clear(t_backup **backup)
{
	if (!backup || !*backup)
		return ;
	if ((*backup)->slots)
		free_null((void **)&(*backup)->slots);
	ft_backup_clear_tracks(&(*backup)->tracker);
	free(*backup);
	*backup = NULL;
}
