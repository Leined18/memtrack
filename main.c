/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/12 11:41:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}

int	ft_addrcmp(void *data1, void *data2)
{
	if (data1 == data2)
		return (0);
	return (1);
}

void	freedom(void **data, t_mt **list)
{
    ft_mtremove(list, ft_mtfind_data(*list, *data));
    if (data && *data)
    {
        free(*data);
        *data = NULL;
    }
}

int	main(void)
{
	t_mt	*list;
	t_mt	*tmp;
	char	*array[7];

	array[0] = ft_strdup("Hello");
	array[1] = ft_strdup("World");
	array[2] = ft_strdup("This");
	array[3] = ft_strdup("Is");
	array[4] = ft_strdup("A");
	array[5] = ft_strdup("Test");
	array[6] = ft_strdup("List");
    list = NULL;
	for (int i = 0; i < 7; i++)
	{
		tmp = ft_mtnew((void **)&array[i]);
		ft_mtadd_back(&list, tmp);
	}
	freedom((void **)&array[2], &list);
	ft_mtprint(list);
	ft_mtclear(&list, ft_mtdel_data);
	return (0);
}
