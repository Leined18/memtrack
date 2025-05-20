/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:47:21 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/20 12:56:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int  setter(int (*s_function)(void **s_ref,char *args[], va_list ap), void **s_ref, const char *str, ...)
{
    if (!str || !s_function)
        return (0);
    va_list ap;
    int result;
    char **args;
    int i;
    
    va_start(ap, str);
    args = ft_split(str, '%');
    if (!args)
        return (0);
    result = s_function(s_ref, args, ap);
    i = 0;
    if (args)
    {
        while (args[i])
            free(args[i++]);
        free(args);
    }
    return (va_end(ap), result);
}