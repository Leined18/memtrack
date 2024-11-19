/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 11:00:43 by danpalac         ###   ########.fr       */
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
void	print_node(void *data)
{
	printf("Node value: %d\n", *(int *)data);
}
// Main para probar todas las funciones
// Main para pruebas

int	main(void)
{
	t_stack *stacka;
	t_stack *stackb;
	t_stack *stackc;

	stacka = ft_stknew(ft_mtnew("dog"), "animals");
	stackb = ft_stknew(ft_mtnew("hammer"), "objects");
	ft_stkadd_mt_back(&stacka, ft_mtnew("mu"));
	ft_stkadd_mt_back(&stacka, ft_mtnew("le"));
	ft_stkadd_mt_back(&stacka, ft_mtnew("asd"));
	ft_stkadd_mt_back(&stacka, ft_mtnew("ñe"));
	ft_stkadd_mt_back(&stacka, ft_mtnew("sa"));
	ft_stkadd_mt_back(&stackb, ft_mtnew("pi"));

	ft_stkprint(stacka, 1, " -> ");
	ft_stkprint(stackb, 1, " -> ");

	stackc = ft_stkzip(&stacka);
	char **arr = ft_calloc(3, sizeof(char *));
	ft_stkadd_mt_back(&stackc, ft_mtnew(arr, sizeof(char *), 3));
	ft_stkprint(stackc, 0, " -> ");

	stacka = ft_stkunzip(&stackc);
	ft_stkprint(stacka, 1, " -> ");

	/* ft_stkprint(stacka, 1, " -> ");
	ft_stkprint(stackb, 1, " -> "); */

	chaosmatrix(0, 0, CLEAR);
	ft_mtprint(chaosmatrix(0, 0, LIST_PTR), 0, " -> ");

	print_title("All tests completed");
	return (0);
}
