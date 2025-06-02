/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 15:24:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	main(void)
{
	t_backup	*backup;

	backup = ft_backup_static(10, true, false); // Crear un backup estático con 10 ranuras
	if (!backup)
	{
		ft_putstr_fd("Error al crear el backup estático\n", 2);
		return (1);
	}
	t_mt	*node1 = ft_mtnew("Node1");
	if (!node1)
	{
		ft_putstr_fd("Error al crear el nodo Node1\n", 2);
		ft_backup_clear(&backup);
		return (1);
	}
	ft_mtnew("Node2");
	backup = ft_backup_static(1, false, false);
	ft_mtnew("Node3"); // Crear otro nodo para verificar el backup
	ft_mtnew("Node4"); // Crear otro nodo para verificar el backup
	ft_mtdelete("Node1"); // Eliminar el nodo Node1 del backup
	ft_mtdelete("Node2"); // Eliminar el nodo Node2 del backup
	ft_mtdelete("Node3"); // Eliminar el nodo Node3 del backup
	ft_mtdelete("Node4"); // Eliminar el nodo Node4 del backup
	ft_mtnew("Node5"); // Crear un nuevo nodo para verificar el backup
	printf("Backup item count: %zu\n", backup->item_count);
	printf("Backup slot count: %zu\n", backup->slot_count);
	printf("Backup slots: %p\n", (void *)backup->slots);
	
	return (0);
}
