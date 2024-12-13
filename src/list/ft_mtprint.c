/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 13:15:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	clear_screen(void)
{
	printf("\033[2J\033[H");
}

void	move_cursor(int x, int y)
{
	printf("\033[%d;%dH", y, x);
}

void	print_box(const char *key, const char *data, int x, int y)
{
	move_cursor(x, y);
	printf("┌──────────────┐\n");
	move_cursor(x, y + 1);
	printf("│ Key: %-8s│\n", key ? key : "NULL");
	move_cursor(x, y + 2);
	printf("│ Data: %-7s│\n", data ? data : "NULL");
	move_cursor(x, y + 3);
	printf("└──────────────┘\n");
}

void	ft_mtprint(t_mt *mt)
{
	print_box(mt->key, (char *)mt->data, 0, 0);
}
