/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:53:35 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/20 13:00:07 by danpalac         ###   ########.fr       */
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

static void set_label(t_data *data, char *label)
{
	if (data->label)
		free(data->label);
	data->label = ft_strdup(label);
}

int ft_data_setter(void **s_ref, char *args[], va_list ap)
{
	int		i;

	if (!s_ref || !args)
		return (0);
	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "id", 2) == 0)
			((t_data *)*s_ref)->id = va_arg(ap, int);
		else if (ft_strncmp(args[i], "item", 4) == 0)
            set_item(((t_data *)*s_ref), va_arg(ap, void *));
		else if (ft_strncmp(args[i], "alloc", 5) == 0)
			((t_data *)*s_ref)->alloc = va_arg(ap, int);
		else if (ft_strncmp(args[i], "size", 4) == 0)
			((t_data *)*s_ref)->size = va_arg(ap, size_t);
		else if (ft_strncmp(args[i], "type", 4) == 0)
			((t_data *)*s_ref)->type = va_arg(ap, int);
		else if (ft_strncmp(args[i], "label", 5) == 0)
			set_label(((t_data *)*s_ref), va_arg(ap, char *));
		else if (ft_strncmp(args[i], "free", 4) == 0)
			((t_data *)*s_ref)->free = va_arg(ap, void *);
		i++;
	}
	return (1);
}
