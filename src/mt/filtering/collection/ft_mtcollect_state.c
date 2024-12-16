/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcollect_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:16:36 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 17:28:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtcollect_state - Recolecta nodos en un estado específico en un árbol/lista.
 * @mt: Nodo raíz o inicio de la lista de nodos a procesar.
 * @state: Estado que se desea recolectar.
 *
 * Return: Lista enlazada de nodos recolectados.
 */

t_mt	*ft_mtcollect_state(t_mt *mt, int state)
{
	t_mt	*collected;

	if (!mt || mt->ptr_aux)
		return (NULL);
	collected = NULL;
	if (mt->values.state == (int)state)
		ft_mtadd_back(&collected, ft_mtdup(mt));
	mt->ptr_aux = "used";
	if (mt->right)
		ft_mtadd_back(&collected, ft_mtcollect_state(mt->right, state));
	if (mt->left)
		ft_mtadd_back(&collected, ft_mtcollect_state(mt->left, state));
	if (mt->parent)
		ft_mtadd_back(&collected, ft_mtcollect_state(mt->parent, state));
	if (mt->children)
		ft_mtadd_back(&collected, ft_mtcollect_state(mt->children, state));
	mt->ptr_aux = NULL;
	return (collected);
}
