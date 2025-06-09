/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:13:24 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 18:50:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"
#include <stdio.h>

// === FUNCIONES DE PRUEBA ===

void print_list(t_mt *head)
{
    printf("Lista:");
    while (head)
    {
        printf(" [%s]", (char *)ft_mtget_id(head));
        head = head->next;
    }
    printf("\n");
}

void test_creacion()
{
    printf("\n=== TEST CREACION ===\n");
    t_mt *a = ft_mtnew("numbers", "uno");
    t_mt *b = ft_mtnew("numbers", "dos");
    t_mt *c = ft_mtnew("numbers", "tres");

    ft_mtadd_back(&a, b);
    ft_mtadd_back(&a, c);

    print_list(a);
    ft_mtclear(&a);
}

void test_eliminacion()
{
    printf("\n=== TEST ELIMINACION ===\n");
    t_mt *a = ft_mtnew("letters", "A");
    t_mt *b = ft_mtnew("letters", "B");
    t_mt *c = ft_mtnew("letters", "C");
    t_mt *d = ft_mtnew("letters", "D");

    ft_mtadd_back(&a, b);
    ft_mtadd_back(&a, c);
    ft_mtadd_back(&a, d);
    print_list(a);

    // Eliminar nodo del medio
    ft_mtremove(&a, c, true);
    print_list(a);

    // Eliminar cabeza
    ft_mtremove(&a, a, true);
    print_list(a);

    ft_mtclear(&a);
}

void test_backup()
{
    printf("\n=== TEST BACKUP ===\n");
    t_backup *backup = ft_backup_new(4);

    t_mt *x = ft_mtnew("cords","x");
    t_mt *y = ft_mtnew("cords", "y");
	if (!backup || !x || !y)
	{
		printf("Error al crear el backup o los nodos.\n");
		return;
	}
	

	ft_backup_add(&backup, x);
	ft_backup_add(&backup, y);

	
    t_mt *found = ft_backup_search(backup, "x")->node;
    if (found)
        printf("Encontrado: %s\n", (char *)ft_mtget_id(found));
    else
        printf("No se encontró 'x'\n");

    ft_backup_clear(&backup);
}

void test_search_set()
{
	ft_backup_static(1, true, false); // Inicializa el backup estático
    printf("\n=== TEST GET/SET ===\n");
    t_mt *node = ft_mtnew("nodos", "nodo_001"); // se añade un nodo al backup estático
	t_mt *node2 = ft_mtnew("nodos", "nodo_002"); // se añade otro nodo al backup estático
	t_mt *node3 = ft_mtnew("nodos", "nodo_003"); // se añade otro nodo al backup estático
	t_mt *node4 = ft_mtnew("nodos", "nodo_004"); // se añade otro nodo al backup estático

	ft_mtdelete(node2->id); // Elimina el nodo con clave "nodos"
    node2 = NULL; // Asigna NULL a node2 para evitar uso posterior
    ft_mtset_id(node, "42"); // Establece el ID del nodo
	ft_mtset_data(node, "datos de prueba");
    printf("ID: %s\n",ft_mtget(node->key)->id);
	printf("data: %s", (char *)ft_mtget(node->key)->data); // obtiene el nodo del backup pasado
	printf("data: %s", (char *)ft_mtget("nodos")->data); // obtiene el nodo del backup pasado
	ft_mtset_id(node3, "44"); // Establece el ID del nodo
	printf("ID: %s\n",ft_mtget(node3->key)->id);
	ft_mtset_data(node3, "datos de prueba 3");
	printf("data: %s", (char *)ft_mtget(node3->key)->data); // obtiene el nodo del backup pasado
	ft_mtset_id(node4, "45"); // Establece el ID del nodo
	printf("ID: %s\n",ft_mtget(node4->key)->id);
	ft_mtset_data(node4, "datos de prueba 4");
	printf("data: %s", (char *)ft_mtget(node4->key)->data); // obtiene el nodo del backup pasado
	
	// Limpia el backup estático

	ft_backup_static(0, false, true); // Limpia el backup estático
}

int main(void)
{
    test_creacion();
    test_eliminacion();
    test_backup();
    test_search_set();
    return 0;
}
