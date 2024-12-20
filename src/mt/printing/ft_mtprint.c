/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:26:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// imprime la lista de datos de la lista.
void	ft_mtprint(t_mt *lst, int b, char *c)
{
	if (!lst)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	while (lst) // Recorrer toda la lista
	{
		// Imprimir de acuerdo al tipo de dato solicitado
		if (b == 1 && lst->data) // Imprimir strings
			ft_printf("%s", (char *)lst->data);
		else if (b == 0 && lst->data) // Imprimir direcciones
			ft_printf("%p", lst->data);
		else if (b == 2 && lst->data) // Imprimir enteros
			ft_printf("%d", *(int *)lst->data);
		else if (!lst->data) // Imprimir NULL si no hay datos
			ft_printf("(NULL)");
		// Imprimir el separador solo si no es el último nodo
		if (lst->vect.right)
			ft_printf("%s", c);
		// Avanzar al siguiente nodo
		lst = lst->vect.right;
	}
	// Imprimir salto de línea después de recorrer toda la lista
	printf("\n");
}
