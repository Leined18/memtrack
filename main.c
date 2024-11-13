/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 18:33:11 by danpalac         ###   ########.fr       */
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
	char	**str;
	char	*str2;

	str = chaosmatrix(2, sizeof(char *), 0);
	str[0] = ft_strdup("pancho");
	str[1] = ft_strdup("pancho");
	str2 = ft_strmtdup("pancho");
	printf("str2: %s\n", str2);
	printf("str[0]: %s\n", str[0]);
	printf("str[1]: %s\n", str[1]);
	//chaosmatrix(0, 0, -1);
	if (ft_mtfind_cmp(chaosmatrix(0, 0, 1), str2, ft_strcmp))
		printf("Found\n");
	else
		printf("Not found\n");
	return (0);
}
