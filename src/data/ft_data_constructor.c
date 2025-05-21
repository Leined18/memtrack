/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_constructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:33:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 10:37:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static int set_camp(t_data **data, char *str, va_list ap)
{
	if (!data || !str)
		return (0);
	if (ft_strncmp(str, "id", 2) == 0)
		(*data)->id = va_arg(ap, int);
	else if (ft_strncmp(str, "item", 4) == 0)
		(*data)->item = va_arg(ap, void *);
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

/**
 * ft_data_constructor - Constructor de datos genérico.
    * @args: Argumentos para la construcción del objeto.
    * @ap: Lista de argumentos variables.
    * @c_function: Función de construcción.
*/

void *c_data(t_args *args)
{
	char	**av;
	va_list	ap;
	t_data	*data;

	if (!args || !args->tokens || !args->ap)
		return (NULL);
	av = args->tokens;
	va_copy(ap, args->ap);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	set_camps(&data, av, ap);
	return (data);
}
