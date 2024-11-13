/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmtdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:34:48 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 10:53:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

char	*ft_strmtdup(const char *s1)
{
	char	*ptr;
	int		i;

	ptr = chaosmatrix(ft_strlen(s1) + 1, sizeof(char), 0);
	if (!ptr)
		return (chaosmatrix(0, 0, -1));
    i = 0;
	while (s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
	return (ptr);
}
