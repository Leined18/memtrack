/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:53:35 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 11:39:52 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void set_item(t_data *data, void *item)
{
    if (data->item)
    {
        if (data->alloc)
        {
            if (data->free)
                data->free(data->item);
            else 
                free(data->item);
        }
    }
    data->item = item;
}

static int set_camp(t_data **data, char *str, va_list ap)
{
	if (!data || !str)
		return (0);
	if (ft_strncmp(str, "id", 2) == 0)
		(*data)->id = va_arg(ap, int);
	else if (ft_strncmp(str, "item", 4) == 0)
		set_item((*data), va_arg(ap, void *));
	else if (ft_strncmp(str, "alloc", 5) == 0)
		(*data)->alloc = va_arg(ap, int);
	else if (ft_strncmp(str, "size", 4) == 0)
		(*data)->size = va_arg(ap, size_t);
	else if (ft_strncmp(str, "type", 4) == 0)
		(*data)->type = va_arg(ap, int);
	else if (ft_strncmp(str, "label", 5) == 0)
		(*data)->label = va_arg(ap, char *);
	else if (ft_strncmp(str, "free", 4) == 0)
		(*data)->free = va_arg(ap, void *);
	else
		return (0);
	return (1);
}

static int set_camps(t_data **data, char *tokens[], va_list ap)
{
	int		i;
	char	*str;

	if (!data || !tokens)
		return (0);
	i = -1;
	while (tokens[++i])
	{
		str = ft_strtrim(tokens[i], " ");
		if (!set_camp(data, str, ap))
			return (free(str), 0);
		free(str);
	}
	return (1);
}

int set_data(t_args *args)
{
	if (!args || !args->s_ref || !args->tokens)
		return (0);
	if (set_camps((t_data **)args->s_ref, args->tokens, args->ap) == 0)
		return (0);
	return (1);
}
