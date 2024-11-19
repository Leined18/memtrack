/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 09:13:50 by danpalac         ###   ########.fr       */
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
void	ft_stkprint(t_stack *stack, int type, char *c)
{
	if (!stack)
	{
		ft_printf("(Stack is NULL)\n");
		return ;
	}
	ft_printf("Stack size: %d\n", stack->size);
	ft_printf("Stack head: %p\n", stack->head);
	ft_printf("Stack Name: %s\n", stack->name);
	ft_mtprint(stack->head, type, c);
	ft_printf("Stack tail: %p\n", stack->tail);
	ft_printf("\n");
}

void	ft_stkmigrate_back(t_stack **src, t_stack **dest)
{
	if (!src || !(*src) || !(*src)->head)
		return ;
	ft_mtmigrate_back(&(*src)->head, &(*dest)->head);
	(*src)->tail = ft_mtlast((*src)->head);
	if ((*dest)->size == 0)
		(*dest)->tail = (*dest)->head;
	else
		(*dest)->tail = ft_mtlast((*dest)->head);
	(*src)->size = ft_mtsize((*src)->head);
	(*dest)->size = ft_mtsize((*dest)->head);
}

t_stack	*ft_stkunzip(t_stack **stack)
{
	t_stack	*unzippedlist;
	t_mt	*current;
	t_mt	*unzipped;
	t_stack	*temp_stack;

	if (!stack || !(*stack) || !(*stack)->head)
		return (NULL);
	unzippedlist = ft_stknew(NULL, "unzipped");
	if (!unzippedlist)
		return (NULL);
	while ((*stack)->size > 0)
	{
		current = (*stack)->head;
		unzipped = ft_mtunzip((current->data), current->count);
		if (unzipped)
		{
			temp_stack = ft_stknew(NULL, "temp");
			temp_stack->head = unzipped;
			ft_stkmigrate_back(&temp_stack, &unzippedlist);
			(ft_mtpop(&(*stack)->head), (*stack)->size--);
		}
		else
			ft_stkpush(stack, &unzippedlist);
	}
	return (unzippedlist);
}

t_stack	*ft_stkzip(t_stack **stack)
{
	t_stack	*zip;
	t_mt	*zipdata;

	if (!(*stack) || !(*stack)->head)
		return (NULL);
	zip = ft_stknew(NULL, "zip");
	if (!zip)
		return (NULL);
	zipdata = ft_mtzip(&(*stack)->head);
	ft_mtpush(&zipdata, &zip->head);
	(*stack) = NULL;
	return (zip);
}

void	ft_stkadd_mt_back(t_stack **stack, t_mt *new)
{
	if (!stack || !new)
		return ;
	while (new)
	{
		ft_mtpush_back(&new, &(*stack)->head);
		(*stack)->tail = ft_mtlast((*stack)->head);
		(*stack)->size++;
	}
	(*stack)->tail = ft_mtlast((*stack)->head);
	(*stack)->size = ft_mtsize((*stack)->head);
}

void	ft_stkadd_mtlist_back(t_stack **stack, t_mt **new)
{
	t_mt	*tmp;

	if (!stack || !new)
		return ;
	tmp = *new;
	while (tmp)
	{
		if (!(*stack))
			(*stack) = ft_stknew(NULL, "temp");
		ft_mtpush_back(&tmp, &(*stack)->head);
	}
	(*stack)->tail = ft_mtlast((*stack)->head);
	(*stack)->size = ft_mtsize((*stack)->head);
}

void	ft_stkadd_stk_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	ft_stkmigrate_back(&new, stack);
}

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
	ft_stkadd_mt_back(&stackc, ft_mtzip(ft_splitmt("pisodemicasaisolaiasmdasime ", 'i')));
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