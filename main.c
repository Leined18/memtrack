/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 19:46:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

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

int	compare_node(t_mt *node, const char *key)
{
	if (!node || !key)
		return (0);
	return (ft_strcmp(node->key, key) == 0);
}

t_mt	*search_in_children(t_mt *parent, const char *key, int (*cmp)(t_mt *,
			const char *))
{
	t_mt	*result;
	t_mt	*child;

	child = (t_mt *)parent->data;
	while (child)
	{
		// Si encontramos el nodo, lo devolvemos
		if (cmp(child, key))
			return (child);
		// Si no lo encontramos, buscamos en los hijos de este nodo
		if (child->type == LIST)
		{
			result = search_in_children(child, key, cmp);
			if (result)
				return (result);
		}
		child = child->next;
	}
	return (NULL);
}

t_mt	*search_node(t_mt *root, const char *key, int (*cmp)(t_mt *,
			const char *))
{
	if (!root || !key || !cmp)
		return (NULL);
	// Si el nodo raíz tiene la clave que estamos buscando
	if (cmp(root, key))
		return (root);
	if (root->type == LIST)
		return (search_in_children(root, key, cmp));
	return (NULL); // Si no encontramos el nodo en ningún lado
}

int	test_compare_node(void)
{
	t_mt	*node1;
	t_mt	*node2;
	t_mt	*node3;

	node1 = ft_mtnew("test", NULL, STRING);
	node2 = ft_mtnew("test", NULL, STRING);
	node3 = ft_mtnew("different", NULL, STRING);
	// Comprobamos si las claves coinciden
	if (compare_node(node1, "test") != 1)
		return (0); // Debe ser 1 porque son iguales
	if (compare_node(node2, "test") != 1)
		return (0); // Debe ser 1 porque son iguales
	if (compare_node(node3, "test") != 0)
		return (0); // Debe ser 0 porque son diferentes
	return (1);     // Prueba exitosa
}

int	test_search_in_children(void)
{
	t_mt	*child1;
	t_mt	*child2;
	t_mt	*parent;
	t_mt	*result;

	child1 = ft_mtnew("child1", NULL, STRING);
	child2 = ft_mtnew("child2", NULL, STRING);
	ft_mtadd_back(&child1, child2);
	parent = ft_mtnew("parent", child1, LIST);
	result = search_in_children(parent, "child2", compare_node);
	if (!result || ft_strcmp(result->key, "child2") != 0)
		return (0); // Debe encontrar child2
	result = search_in_children(parent, "child3", compare_node);
	if (result)
		return (0); // No debe encontrar ningún nodo con esta clave
	return (1);     // Prueba exitosa
}

int	test_search_node(void)
{
	t_mt	*greatgrandchild;
	t_mt	*grandchild;
	t_mt	*child1;
	t_mt	*parent;
	t_mt	*result;

	// Crear nodos
	greatgrandchild = ft_mtnew("greatgrandchild", NULL, STRING);
	grandchild = ft_mtnew("grandchild", greatgrandchild, LIST);
	child1 = ft_mtnew("child1", grandchild, LIST);
	parent = ft_mtnew("parent", child1, LIST);
	// Buscar "greatgrandchild" en el árbol
	result = search_node(parent, "greatgrandchild", compare_node);
	if (!result || ft_strcmp(result->key, "greatgrandchild") != 0)
		return (0); // Debe encontrar greatgrandchild
	// Buscar "grandchild" en el árbol
	result = search_node(parent, "grandchild", compare_node);
	if (!result || ft_strcmp(result->key, "grandchild") != 0)
		return (0); // Debe encontrar grandchild
	// Buscar "child1" en el árbol
	result = search_node(parent, "child1", compare_node);
	if (!result || ft_strcmp(result->key, "child1") != 0)
		return (0); // Debe encontrar child1
	// Buscar "parent" en el árbol
	result = search_node(parent, "parent", compare_node);
	if (!result || ft_strcmp(result->key, "parent") != 0)
		return (0); // Debe encontrar parent
	// Intentar buscar un nodo inexistente
	result = search_node(parent, "nonexistent", compare_node);
	if (result)
		return (0); // No debe encontrar ningún nodo con esta clave
	return (1); // Prueba exitosa
}

int	test_hash_table_operations(void)
{
	t_hash_table	*ht;
	t_mt			*arr;
	t_mt			*result;

	ht = ft_mtnew_hash_table(3);
	if (!ht)
		return (0);
	// Insertamos datos en la tabla hash
	arr = ft_splitmt("HOME/DANPALAC/BIN:USR/BIN:KERNEL/BIN", ':');
	ft_mthash_insert(ht, "PATH", arr, LIST);
	ft_mthash_insert(ht, "NUMBERS", ft_mtnew("DECIMAL", ft_strdup("1234567890"),
			STRING), LIST);
	ft_mthash_insert(ht, "LETTERS", ft_mtnew("LATIN", ft_strdup("ABCDEFGHIJ"),
			STRING), LIST);
	ft_mthash_insert(ht, "HOLA", ft_strdup("hola"), STRING);
	// Comprobamos si "PATH" se ha insertado correctamente
	result = ft_mthash_find(ht, "PATH");
	if (!result || ft_strcmp(result->key, "PATH") != 0)
		return (0);
	// Comprobamos la eliminación de "NUMBERS"
	ft_mthash_remove(ht, "NUMBERS");
	result = ft_mthash_find(ht, "NUMBERS");
	if (result)
		return (0); // No debe encontrar "NUMBERS" después de eliminarlo
	// Comprobamos la actualización de "HOLA"
	ft_mthash_insert(ht, "HOLA", ft_strdup("adios"), STRING);
	result = ft_mthash_find(ht, "HOLA");
	if (!result || ft_strcmp((char *)result->data, "adios") != 0)
		return (0);
	ft_mtfree_hash_table(ht); // Liberamos la tabla hash
	return (1);               // Prueba exitosa
}

int	main(void)
{
	if (!test_compare_node())
	{
		ft_printf("Test compare_node failed\n");
		return (1);
	}
	if (!test_search_in_children())
	{
		ft_printf("Test search_in_children failed\n");
		return (1);
	}
	if (!test_search_node())
	{
		ft_printf("Test search_node failed\n");
		return (1);
	}
	if (!test_hash_table_operations())
	{
		ft_printf("Test hash table operations failed\n");
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
