/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:38:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:14:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_free - Libera la memoria de la estructura de backup.
 * @backup: Doble puntero a la estructura de backup.
 *
 * Esta función libera la memoria ocupada por la estructura de backup y sus
 * elementos. Se asegura de liberar todos los slots y el tracker asociado.
 */

void	ft_backup_free(t_backup **backup)
{
	t_slot	*slot;
	t_slot	*temp;

	if (!backup || !*backup)
		return ;
	slot = (*backup)->slots;
	while (slot)
	{
		temp = slot->next;
		free(slot);
		slot = temp;
	}
	ft_lstclear(&(*backup)->tracker, ft_mtdelete);
	free(*backup);
	*backup = NULL;
}
