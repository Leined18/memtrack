/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 02:17:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * test_hash_table_operations - Prueba las operaciones de la tabla hash.
 *
 * Retorna 1 si la prueba fue exitosa, 0 si falló.
 */

int	test(t_hash_table **ht)
{
	(*ht) = ft_mthash_new_table(3, "test");
	(*ht)->methods.insert_child((*ht), "key1", "data1", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.insert_child((*ht), "key1", "data2", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.insert_child((*ht), "key1", "data3", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.insert_child((*ht), "key1", "data4", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.insert_child((*ht), "key1", "data5", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.insert_child((*ht), "key1", "data6", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.insert_child((*ht), "key1", "data7", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.insert_child((*ht), "data7", "data8", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.insert_child((*ht), "data8", "data9", ft_strdup("xkasjd23"),
		STRING);
	(*ht)->methods.remove((*ht), "data8");
	(*ht)->methods.print((*ht));
	(*ht)->methods.free_table((*ht));
	return (1);
}

int	main(void)
{
	t_hash_table	*ht;

	ht = NULL;
	if (!test(&ht))
	{
		ft_printf("Test failed\n");
		if (ht)
			ht->methods.free_table(ht);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
