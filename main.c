/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 08:56:37 by danpalac         ###   ########.fr       */
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
	t_mt	*str;
	char	*str2;

	str = NULL;
	str2 = ft_strmtdup("Hola");
	ft_mtpush_data(&str, ft_split("Hola que tal", ' '));
	ft_mtpush_data(&str, ft_strdup("Que tal"));
	ft_mtpush_data(&str, ft_strdup("Miau"));
	ft_mtprint(chaosmatrix(0, 0, 1), 1);
	ft_mtprint(str, 0);
	(void)str;
	(void)str2;
	return (0);
}
