/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_submtstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:00:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 10:01:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

char	*ft_submtstr(char const *s, unsigned int start, size_t len)
{
    char	*ptr;
    size_t	i;

    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (ft_strmtdup(""));
    ptr = chaosmatrix(len + 1, sizeof(char), 0);
    if (!ptr)
        return (chaosmatrix(0, 0, -1));
    i = 0;
    while (s[start] && i < len)
    {
        ptr[i] = s[start];
        i++;
        start++;
    }
    ptr[i] = '\0';
    return (ptr);
}
