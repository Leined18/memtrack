/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconstructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:40:47 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 11:12:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static int set_camp_2(t_mt **obj, char *str, va_list ap)
{
    if (!obj || !str)
        return (0);
    if (ft_strncmp(str, "status", 6) == 0)
        (*obj)->status = va_arg(ap, int);
    else if (ft_strncmp(str, "type", 4) == 0)
        (*obj)->type = va_arg(ap, int);
    else if (ft_strncmp(str, "free", 4) == 0)
        (*obj)->free = va_arg(ap, void *);
    else
        return (0);
    return (1);
}

static int set_camp_1(t_mt **obj, char *str, va_list ap)
{
    if (!obj || !str)
        return (0);
    if (ft_strncmp(str, "id", 2) == 0)
        (*obj)->id = va_arg(ap, int);
    else if (ft_strncmp(str, "key", 4) == 0)
        (*obj)->key = ft_strdup(va_arg(ap, char *));
    else if (ft_strncmp(str, "data", 5) == 0)
        (*obj)->data = va_arg(ap, void *);
    else if (ft_strncmp(str, "aux", 4) == 0)
        (*obj)->aux = va_arg(ap, t_mt *);
    else if (ft_strncmp(str, "links", 4) == 0)
        (*obj)->links = va_arg(ap, void *);
    else if (ft_strncmp(str, "backup", 5) == 0)
        (*obj)->backup = va_arg(ap, t_backup *);
    else if (ft_strncmp(str, "cords", 4) == 0)
        (*obj)->cords = va_arg(ap, t_cords *);
    else
        return (0);
    return (1);
}


static int set_camps(t_mt **obj, char *tokens[], va_list ap)
{
    int		i;
    char	*str;

    if (!obj || !tokens)
        return (0);
    i = -1;
    while (tokens[++i])
    {
        str = ft_strtrim(tokens[i], " ");
        if (!set_camp_1(obj, str, ap) && !set_camp_2(obj, str, ap))
            return (free(str), 0);
        free(str);
    }
    return (1);
}

/**
 * ft_mtconstructor - Constructor de la estructura t_cords.
 * @args: Argumentos para la construcción del objeto.
 * @ap: Lista de argumentos variables.
 *
 * Esta función construye un objeto de tipo t_cords utilizando los argumentos
 * proporcionados. Los argumentos se pasan como una lista variable y se procesan
 * para inicializar los campos de la estructura t_cords.
 *
 * Retorna un puntero al objeto construido o NULL en caso de error.
 */

 void    *c_mt(t_args *args)
 {
    if (!args || !args->tokens || !args->ap)
        return (NULL);
    t_mt *new_mt;
    
    new_mt = ft_calloc(1, sizeof(t_mt));
    if (!new_mt)
        return (NULL);
    set_camps(&new_mt, args->tokens, args->ap);
    return (new_mt);
 }
 