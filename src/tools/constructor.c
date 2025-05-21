/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:26:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 10:10:07 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * @brief Constructor function that takes a string and a function pointer, to construct an object.
 * @param c_function The function to be called for construction.
 * @param str The string to be split and passed to the function.
 * @param ... The variable arguments to be passed to the function, to set the values. 
 */

void *constructor(void *(*c_function)(t_args *args), const char *str, ...)
{
    if (!str || !c_function)
        return (NULL);
    va_list ap;
    void *result;
    char **tokens;
    int i;
    t_args args_ref;

    va_start(ap, str);
    tokens = ft_split(str, '%');
    if (!tokens)
        return (NULL);
    args_ref.tokens = tokens;
    args_ref.count = 0;
    va_copy(args_ref.ap, ap);
    while (tokens[args_ref.count])
        args_ref.count++;
    result = c_function(&args_ref);
    i = 0;
    while (tokens[i])
        free(tokens[i++]);
    free(tokens);
    return (va_end(ap), result);
}

