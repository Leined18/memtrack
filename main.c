/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 09:18:39 by danpalac         ###   ########.fr       */
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
	if (list && *list && data && *data)
		ft_mtremove(list, ft_mtfind_data(*list, *data));
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
}

void	*chaosmatrix(int count, size_t size, int flag)
{
	void		*ptr;
	t_mt		*tmp;
	static t_mt	*list = NULL;

	if (flag == -1)
	{
		ft_mtclear(&list, ft_mtdel_data);
		return (NULL);
	}
	if (flag)
		return (list);
	ptr = NULL;
	ptr = malloc(count * size);
	if (ptr)
	{
		ft_memset(ptr, 0, count * size);
		tmp = ft_mtnew(&ptr);
		tmp->size = size;
		tmp->count = count;
		ft_mtadd_front(&list, tmp);
		return (ptr);
	}
	return (NULL);
}

int	main(void)
{
	char	**array;
	char	*str;
	t_mt	*list;

	array = chaosmatrix(1, sizeof(char *), 0);
	str = chaosmatrix(7, sizeof(char), 0);
	array[0] = ft_strdup("Hello");
	(void)list;
	(void)array;
	(void)str;
	chaosmatrix(0, 0, -1);
    printf("SUCCESS\n");
	return (0);
}
