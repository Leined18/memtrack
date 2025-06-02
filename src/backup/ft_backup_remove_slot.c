/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_remove_slot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:53:06 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 15:20:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_remove_slot - Elimina una ranura del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @slot: Puntero a la ranura a eliminar.
 * @free_slot: Booleano que indica si se debe liberar la memoria de la ranura.
 *
 * Esta función elimina una ranura del backup y libera su memoria.
 * Se asegura de eliminar la ranura de la lista de ranuras y liberar su memoria.
 */

 
void	ft_backup_remove_slot(t_backup **backup, t_mt *slot, bool free_slot)
{
    t_mt	*cur;
    size_t	i;

    if (!backup || !(*backup)->slots || !slot)
        return ;
    
    cur = (*backup)->slots[0];
    i = 0;
    while (i < (*backup)->slot_count)
    {
        if (cur == slot)
        {
            ft_mtremove(&(*backup)->slots[i], slot, free_slot);
            return ;
        }
        cur = (*backup)->slots[i];
        i++;
    }
}