/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 17:57:02 by danpalac         ###   ########.fr       */
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
	ht = ft_mthash_new_table(3, "Test");
	ht->put(ht, "ANIMALS", ft_splitmt("dog:cat:rabbit", ':'), BRANCH);
	ht->put(ht, "OBJECTS", ft_splitmt("hammer:fork:cube", ':'), BRANCH);
	ht->put(ht, "COLORS", ft_splitmt("red:blue:green", ':'), BRANCH);
	ht->put(ht, "BASURA", NULL, LEAF);
	ht->remove(ht, "cat");
	// recuerda siempre en el parametro data, enviar data allocada con malloc
	ht->add_child(ht, "ANIMALS", ft_mtnew("bird", ft_strdup("pigeon"), LEAF));
	ht->add_child(ht, "ANIMALS", ft_mtnew("descriptions", ft_mtnew("bird_d",
				ft_strdup("los pajaros"), LEAF), BRANCH));
	ht->add_child(ht, "descriptions", ft_mtnew("dog_d", ft_strdup("los perros"),
			LEAF));
	ht->add_child(ht, "descriptions", ft_mtnew("rabbit_d", ft_mtnew("white_rabbit",
                ft_strdup("los conejos blancos"), LEAF), BRANCH));
	ht->add_child(ht, "rabbit_d", ft_mtnew("hash", ft_mthash_new_table(3, "child"), HASH_TABLE));
	printf("\n");
	ht->print(ht);
	printf("%d\n", ft_mthash_count_type(ht, BRANCH));
	ht->free_table(ht); // solo eliminamos esta tabla,
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
