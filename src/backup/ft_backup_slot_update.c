/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_slot_update.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:02:20 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 13:46:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_slot_update - Actualiza el número de ranuras en el backup.
 * @slots: Doble puntero a la lista de ranuras del backup.
 * @new_slot_count: Nuevo número de ranuras a establecer.
 */

void ft_backup_slot_update(t_backup **backup, size_t new_slot_count)
{
    if (!backup || !*backup || new_slot_count == 0)
     return;
    (*backup)->slots = ft_realloc((*backup)->slots,
    (*backup)->slot_count * sizeof(t_mt *), new_slot_count * sizeof(t_mt *));
    (*backup)->slot_count = new_slot_count;
}
    