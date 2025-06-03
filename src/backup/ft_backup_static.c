/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_static.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:09:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 23:51:34 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_static - Crea un backup estático de un nodo t_mt.
 * @slot_count: Número de ranuras en el backup.
 * @new booleano que determina si creas un nuevo backup mas el @slotcount
 * @clear booleano que determina si limpias el backup, new + clear reinicia el backup
sin new, solo limpia y retorna nulo.
 * Retorna:
 *   Un puntero a la estructura de backup creada.
 */
 
t_backup *ft_backup_static(size_t slot_count, bool new, bool clear)
{
    static t_backup *backup = NULL;
    
    if (backup && !new && !clear && (slot_count == backup->slot_count || !slot_count))
        return (backup); // Retorna el backup existente si no se solicita una nueva creación ni limpieza
    if (!backup && slot_count > 0 && new && !clear)
        backup = ft_backup_new(slot_count); // crea solo una vez
    else if (backup && new && clear)
    {
        ft_backup_clear(&backup); // limpia el backup existente
        return (ft_backup_static(slot_count, true, false)); // reinicia el backup
    }
    else if (backup && clear && !new) // si solo se solicita limpieza
        return (ft_backup_clear(&backup), NULL);
    else if (backup && !clear && new && slot_count > 0)
    {
        ft_backup_slot_update(&backup, slot_count); // Actualiza el número de ranuras del backup existente
        return (backup);
    }
    return (backup);
}
