/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 13:29:06 by danpalac         ###   ########.fr       */
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

t_mt  *ft_build_line(t_mt **start, t_cords origin, t_offset offset, t_backup **backup)
{
    t_offset step;
	t_cords pos;
	t_mt *current;
	int count;
	int idx;
	char *key;
	
	step = ft_offset_new(offset.direction, offset.elevation, 1.0f);
    pos = origin;
    current = *start;
    count = (int)(offset.distance);
	idx = 0;
    while (count > 0)
    {
		key = ft_itoa(idx);
        t_mt *node = ft_mtnew2(key, NULL, backup);
		free(key);
        if (!node)
           break;
        pos = ft_calc_cords_3d(pos, step);
        node->cords = pos;
        ft_mtadd_link(&current, node, step, NULL);
        current = node;
        count--;
		idx++;
    }
	return (current);
}


int	main(int ac, char **av)
{
	if (ac != 4)
	{
		ft_printf(RED "Usage: %s <direction> <elevation> <distance>\n" RESET, av[0]);
		return (1);
	}
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[1]) > 360)
	{
		ft_printf(RED "Direction must be between 0 and 360 degrees\n" RESET);
		return (1);
	}
	if (ft_atoi(av[2]) < 0 || ft_atoi(av[2]) > 360)
	{
		ft_printf(RED "Elevation must be between 0 and 360 degrees\n" RESET);
		return (1);
	}
	if (ft_atoi(av[3]) < 0)
	{
		ft_printf(RED "Distance must be greater than 0\n" RESET);
		return (1);
	}
	t_backup	*backup;
	t_mt		*start;
	t_cords		origin = ft_cords_new(0, 0, 0);
	t_offset	offset = ft_offset_new_degrees(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]));
	t_mt		*node;

	(void)ac;
	backup = ft_backup_new(30);
	start = ft_mtnew2("start", NULL, &backup);
	node = ft_build_line(&start, origin, offset, &backup);
	printf("Final position: (%.2f, %.2f, %.2f)\n", node->cords.x, node->cords.y, node->cords.z);
	node = ft_backup_get(backup, "4");
	if (node)
	{
		printf("Node 4 position Removed: (%.2f, %.2f, %.2f)\n", node->cords.x, node->cords.y, node->cords.z);
		ft_backup_remove(&backup, node);
	}
	if (backup)
	{
		printf("Backup items: %zu\n", backup->item_count);
		ft_backup_clear(&backup);
	}
	else
	{
		ft_printf(RED "Backup is NULL\n" RESET);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
