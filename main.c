/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 18:38:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Funciones auxiliares para mostrar gráficos
void	print_title(const char *title)
{
	printf("\n%s\n", "==========================");
	printf("   %s\n", title);
	printf("%s\n\n", "==========================");
}
int	cmp_int(void *a, void *b, size_t n)
{
	(void)n; // Evitar advertencias por parámetro no utilizado
	return (*(int *)a - *(int *)b);
}

int	main(void)
{
	t_hash_table	*ht;
	t_mt			*arr;

	ht = ft_mtnew_hash_table(3);
	if (!ht)
		return (1);
	arr = ft_splitmt("HOME/DANPALAC/BIN:USR/BIN:KERNEL/BIN", ':');
	ft_mthash_insert(ht, "PATH", arr, LIST);
	ft_mthash_insert(ht, "NUMBERS", ft_mtnew("DECIMAL", ft_strdup("1234567890"),
			STRING), LIST);
	ft_mthash_insert(ht, "LETTERS", ft_mtnew("LATIN", ft_strdup("ABCDEFGHIJ"),
			STRING), LIST);
	ft_mthash_insert(ht, "HOLA", ft_strdup("hola"), STRING);
	ft_mtprint_hash_table(ht);
	print_title("FINDING DATA");
	arr = (t_mt *)ft_mthash_find(ht, "PATH");
	if (arr)
	{
		ft_printf("DATA: %s\n", (char *)arr->data);
		ft_printf("KEY: %s\n", arr->key);
	}
	print_title("REMOVING DATA");
	ft_mthash_remove(ht, "NUMBERS");
	ft_mtprint_hash_table(ht);
	print_title("REPLACING DATA");
	ft_mthash_insert(ht, "HOLA", ft_strdup("adios"), STRING);
	ft_mtprint_hash_table(ht);
	ft_mtfree_hash_table(ht);
	return (0);
}
