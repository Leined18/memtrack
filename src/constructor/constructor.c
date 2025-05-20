/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:26:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/20 12:42:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * @brief Constructor function that takes a string and a function pointer, to construct an object.
 * @param c_function The function to be called for construction.
 * @param str The string to be split and passed to the function.
 * @param ... The variable arguments to be passed to the function, to set the values. 
 */

void *constructor(void *(*c_function)(char *args[], va_list ap), const char *str, ...)
{
    if (!str || !c_function)
        return (NULL);
    va_list ap;
    void *result;
    char **args;
    int i;
    
    va_start(ap, str);
    args = ft_split(str, '%');
    if (!args)
        return (NULL);
    result = c_function(args, ap);
    i = 0;
    if (args)
    {
        while (args[i])
            free(args[i++]);
        free(args);
    }
    return (va_end(ap), result);
}

