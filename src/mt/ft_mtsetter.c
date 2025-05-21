/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsetter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:59:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 11:12:16 by danpalac         ###   ########.fr       */
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
        set_mem((void **)&(*obj)->key, ft_strdup(va_arg(ap, char *)));
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


int set_mt(t_args *args)
{
    t_mt	**obj;
    int		i;
    char	*str;

    if (!args || !args->tokens || !args->s_ref)
        return (0);
    obj = (t_mt **)args->s_ref;
    i = -1;
    while (args->tokens[++i])
    {
        str = ft_strtrim(args->tokens[i], " ");
        if (!set_camp_1(obj, str, args->ap) && !set_camp_2(obj, str, args->ap))
            return (free(str), 0);
        free(str);
    }
    return (1);
}