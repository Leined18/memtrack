/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 11:26:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

int	ft_strcmp(void *data, void *data2)
{
	if (strcmp(data, data2) == 0)
		return (0);
	return (1);
}

int	ft_addresscmp(void *data, void *data2)
{
	if (data == data2)
		return (0);
	return (1);
}

int	main(void)
{
	char	*str;
	char	*str2;
	t_mt	*tmp;
	t_mt	*res;

	str = ft_strmtdup("mano");
	str2 = ft_strmtdup("Hello");
	(void)str2;
	(void)str;
	tmp = chaosmatrix(0, 0, 1);
	res = ft_mtfind_cmp(tmp, "mano", ft_strcmp);
	if (res)
		printf("Found: %s\n", (char *)res->data);
	else
		printf("Not found\n");
	freedom(&res->data, NULL);
	chaosmatrix(0, 0, -1);
	printf("SUCCESS\n");
	return (0);
}
