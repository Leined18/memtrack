/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 13:43:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * test_hash_table_operations - Prueba las operaciones de la tabla hash.
 *
 * Retorna 1 si la prueba fue exitosa, 0 si falló.
 */

int	test(t_hash_table *ht)
{
	ht = ft_mtnew_hash_table(3);
	ht->put(ht, "ANIMALS", ft_splitmt("dog:cat:rabbit", ':'), BRANCH);
    ht->put(ht, "OBJECTS", ft_splitmt("hammer:fork:cube", ':'), BRANCH);
    ht->put(ht, "COLORS", ft_splitmt("red:blue:green", ':'), BRANCH);
    ht->put(ht, "BASURA", NULL, BRANCH);
    ht->remove(ht, "cat");
    // recuerda siempre en el parametro data, enviar data allocada con malloc
    ht->add_child(ht, "ANIMALS", ft_mtnew("bird", ft_strdup("pigeon"), LEAF));
    printf("\n");
    ht->print(ht);
	ht->free_table(ht); // solo eliminamos esta tabla, la otra se elimina en la función free_table
	return (1);
}

int	main(void)
{
	t_hash_table	*ht;

	ht = NULL;
	if (!test(ht))
	{
		ft_printf("Test failed\n");
		if (ht)
			ht->free_table(ht);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
