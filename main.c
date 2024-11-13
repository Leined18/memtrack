/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 10:05:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

int	main(void)
{
	char	*str;
	char	*sub;

	str = ft_strmtdup("Hello WOSFAJSKFJAKS");
	printf("str: %s\n", str);
	sub = ft_submtstr(str, 6, 5);
    printf("sub: %s\n", sub);
	chaosmatrix(0, 0, -1);
	printf("SUCCESS\n");
	return (0);
}
