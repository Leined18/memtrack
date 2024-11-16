/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 15:22:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// Funciones auxiliares para mostrar gráficos
void	print_title(const char *title)
{
	printf("\n%s\n", "==========================");
	printf("   %s\n", title);
	printf("%s\n\n", "==========================");
}

void	print_list(t_mt *list)
{
	if (!list)
	{
		printf("(NULL)\n");
		return ;
	}
	while (list)
	{
		printf("%d", *(int *)(list->data));
		if (list->next)
			printf(" -> ");
		list = list->next;
	}
	printf("\n");
}

// Función de comparación para enteros
int	cmp_int(void *a, void *b, size_t n)
{
	(void)n; // Evitar advertencias por parámetro no utilizado
	return (*(int *)a - *(int *)b);
}
void	print_node(void *data)
{
	printf("Node value: %d\n", *(int *)data);
}
// Main para probar todas las funciones
// Main para pruebas
int	main(void)
{
	t_mt *list = NULL;
	t_mt *migrated_list = NULL;
	t_mt *node;
	int values[] = {42, 56, 30, 20, 10};

	print_title("Test ft_mtnew");
	node = ft_mtnew_chaos(&values[0]);
	printf("Node created with value: %d\n", *(int *)(node->data));
	ft_mtadd_back(&list, node);
	print_list(list);

	print_title("Test ft_mtadd_back");
	ft_mtadd_back(&list, ft_mtnew(&values[1]));
	printf("List after adding node: ");
	print_list(list);

	print_title("Test ft_mtpush_data");
	ft_mtpush_data(&list, &values[2]);
	printf("List after pushing data: ");
	print_list(list);

	print_title("Test ft_mtremove");
	ft_mtremove(&list, &values[0], cmp_int, sizeof(int));
	printf("List after removing 42: ");
	print_list(list);

	print_title("Test ft_mtsize");
	printf("Size of list: %d\n", ft_mtsize(list));

	print_title("Test ft_mtclear");
	ft_mtclear(&list, ft_mtdel_data);
	printf("List after clear: ");
	print_list(list);

	print_title("Test ft_mtiter");
	ft_mtpush_data(&list, &values[3]);
	ft_mtpush_data(&list, &values[2]);
	ft_mtpush_data(&list, &values[4]);
	ft_mtpush_data(&list, &values[1]);
	ft_mtiter(list, print_node);

	print_title("Test ft_mtpush_back");
	ft_mtpush_back(&list, &migrated_list);
	ft_mtpush_back(&list, &migrated_list);
	printf("List after pushing back to new list:\n");
	printf("Old List: ");
	print_list(list);
	printf("New List: ");
	print_list(migrated_list);

	print_title("Test ft_mtrotate");
	ft_mtrotate(&migrated_list);
	printf("List after rotate: ");
	print_list(migrated_list);

	printf("List before swap: ");
	print_list(migrated_list);
	ft_mtswap(&migrated_list);
	printf("List after swap: ");
	print_list(migrated_list);

	print_title("Test ft_mtmigrate");
	ft_mtmigrate(&migrated_list, &list);
	printf("List after migrate to new list:\n");
	printf("Source List: ");
	print_list(migrated_list);
	printf("Destination List: ");
	print_list(list);

	print_title("Test ft_mtreplace");
	ft_mtreplace(list, &values[2], &values[0], cmp_int, sizeof(int));
	printf("List after replace 30 with 42: ");
	print_list(list);

	print_title("Test ft_mtinsert_index");
	ft_mtinsert_index(&list, ft_mtnew(&values[2]), 2);
	printf("List after insert 30 at index 2: ");
	print_list(list);

	print_title("Test ft_mtreverse_rotate");
	ft_mtreverse_rotate(&list);
	printf("List after reverse rotate: ");
	print_list(list);

	/* print_title("Test ft_mtswap_nodes");
	ft_mtswap_nodes(&list, list, list->next);
	printf("List after swap nodes: ");
	print_list(list); */

	print_title("All tests completed");
	return (0);
}