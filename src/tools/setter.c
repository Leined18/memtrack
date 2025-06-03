/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:47:21 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 21:53:55 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int  setter(int (*s_function)(t_args *args), void **s_ref, const char *str, ...)
{
    if (!str || !s_function)
        return (0);
    va_list ap;
    int result;
    char **args;
    int i;
    t_args args_ref;
    
    va_start(ap, str);
    args = ft_split(str, '%');
    if (!args)
        return (0);
    args_ref.tokens = args;
    args_ref.count = 0;
    va_copy(args_ref.ap, ap);
    while (args[args_ref.count])
        args_ref.count++;
    args_ref.s_ref = s_ref;
    result = s_function(&args_ref);
    i = 0;
    while (args[i])
        freec(args[i++]);
    freec(args);
    return (va_end(ap), result);
}
