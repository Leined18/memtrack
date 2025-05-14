/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 19:32:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

bool filter(t_mt *node, t_data data)
{
	if (data.item)
	{
		if (ft_strncmp(data.label, "cmp", 3) == 0)
		{
			if (ft_strncmp(node->key, data.item, data.size) == 0)
				return (true);
		}
	}
	return (false);
}

t_mt  *ft_build_line(t_mt **start, t_cords origin, t_offset offset)
{
    t_offset step;
	t_cords pos;
	t_mt *current;
	int count;
	
	step = ft_offset_new(offset.direction, offset.elevation, 1.0f);
    pos = origin;
    current = *start;
    count = (int)(offset.distance);
    if (!start)
        return (current);
    while (count > 0)
    {
        t_mt *node = ft_mtnew2("line", NULL, &(*start)->backup);
        if (!node)
           break;
        pos = ft_calc_cords_3d(pos, step);
        node->cords = pos;
        ft_mtaddlast(&current, node, step);
        current = node;
        count--;
    }
	return (current);
}


int	main(void)
{
	t_backup	*backup;
	t_mt		*start = NULL;
	t_cords		origin = ft_cords_new(0, 0, 0);
	t_offset	offset = ft_offset_new_degrees(7.5, DEGREE_FLAT, 1030);
	t_mt		*last;
	backup = NULL;
	start = ft_mtnew2("start", NULL, &backup);
	
	last = ft_build_line(&start, origin, offset);
	printf("Final position: (%.2f, %.2f, %.2f)\n", last->cords.x, last->cords.y, last->cords.z);
	offset = ft_offset_new_degrees(DEGREE_WEST, DEGREE_FLAT, 100);
	last = ft_build_line(&start, last->cords, offset);
	printf("Final position: (%.2f, %.2f, %.2f)\n", last->cords.x, last->cords.y, last->cords.z);
	if (backup)
	{
		printf("Backup items: %zu\n", backup->item_count);
		ft_backup_free(&backup);
	}
	else
	{
		ft_printf(RED "Backup is NULL\n" RESET);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
