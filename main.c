/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 23:33:25 by daniel           ###   ########.fr       */
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
	backup = ft_backup_static(20, true, false);
	ft_mtnew("Node3"); // Crear otro nodo para verificar el backup
	ft_mtnew("Node4"); // Crear otro nodo para verificar el backup// Agregar un track para Node1
	ft_mtnew("Node5"); // Crear un nuevo nodo para verificar el backup
	backup = ft_backup_static(0, false, false);
	printf("Backup item count: %zu\n", backup->item_count);
	printf("Backup slot count: %zu\n", backup->slot_count);
	printf("Backup tracker: %p\n", (void *)backup->tracker);
	printf("Backup slots: %p\n", (void *)backup->slots);
	ft_backup_static(0, false, true); // Limpiar el backup estático
	printf("Backup cleared: %d\n", freec(NULL));
	
	
	return (0);
}
