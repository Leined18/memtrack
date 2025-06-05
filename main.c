/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:13:24 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 12:01:30 by danpalac         ###   ########.fr       */
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
        printf(" [%s]", ft_mtget_key(head));
        head = head->next;
    }
    printf("\n");
}

void test_creacion()
{
    printf("\n=== TEST CREACION ===\n");
    t_mt *a = ft_mtnew("uno");
    t_mt *b = ft_mtnew("dos");
    t_mt *c = ft_mtnew("tres");

    ft_mtadd_back(&a, b);
    ft_mtadd_back(&a, c);

    print_list(a);
    ft_mtclear(&a);
}

void test_eliminacion()
{
    printf("\n=== TEST ELIMINACION ===\n");
    t_mt *a = ft_mtnew("A");
    t_mt *b = ft_mtnew("B");
    t_mt *c = ft_mtnew("C");
    t_mt *d = ft_mtnew("D");

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

    t_mt *x = ft_mtnew("x");
    t_mt *y = ft_mtnew("y");

	ft_backup_add(&backup, x);
	ft_backup_add(&backup, y);



    t_mt *found = ft_backup_get(backup, "x");
    if (found)
        printf("Encontrado: %s\n", ft_mtget_key(found));
    else
        printf("No se encontró 'x'\n");

    ft_backup_clear(&backup);
}

void test_get_set()
{
	ft_backup_static(1, true, false); // Inicializa el backup estático
    printf("\n=== TEST GET/SET ===\n");
    t_mt *node = ft_mtnew("nodo"); // se añade un nodo al backup estático

    ft_mtset_id(node, 42);
	ft_mtset_data(node, "datos de prueba");
    printf("ID: %d\n", ft_mtget(node->key)->id);
	printf("data: %s", (char *)ft_mtget(node->key)->data); // obtiene el nodo del backup pasado

    ft_mtfree(node);
	ft_backup_static(0, false, true); // Limpia el backup estático
}

int main(void)
{
    test_creacion();
    test_eliminacion();
    test_backup();
    test_get_set();
    return 0;
}
