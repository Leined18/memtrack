/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdisconnect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:01:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 14:46:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_connect_parent(t_mt **node)
{
	t_mt	*parent;

	if (!node || !(*node) || !(*node)->parent)
		return (*node); // Retorna el nodo original si es inválido
	parent = (*node)->parent;
	if (parent->children == *node)
		parent->children = (*node)->right;
	(*node)->parent = NULL; // Desconectamos el nodo de su padre
	return (*node);
}

t_mt	*ft_connect_siblings(t_mt **node)
{
	if (!node || !(*node))
		return (*node); // Retorna el nodo original si es inválido
	// Si el nodo tiene un hermano izquierdo, actualizamos su puntero 'right'
	if ((*node)->left)
		(*node)->left->right = (*node)->right;
	// Si el nodo tiene un hermano derecho, actualizamos su puntero 'left'
	if ((*node)->right)
		(*node)->right->left = (*node)->left;
	(*node)->left = NULL;
	(*node)->right = NULL;
	return (*node);
}

t_mt	*ft_connect_childrens(t_mt **node)
{
	t_mt	*children;

	if (!node || !(*node) || !(*node)->children)
		return (*node); // Retorna el nodo original si es inválido
	children = (*node)->children;
	if ((*node)->parent && (*node)->parent->parent)
		ft_mtadd_children((*node)->parent->parent, children);
	else if ((*node)->left)
		ft_mtadd_children((*node)->left, children);
	else if ((*node)->right)
		ft_mtadd_children((*node)->right, children);
	(*node)->children = NULL; // Limpiamos la lista de hijos
	return (*node);
}

static void	go_to_existing(t_mt **node)
{
	if (!node || !(*node))
		return ;
	if ((*node)->parent)
		*node = (*node)->parent;
	else if ((*node)->right)
		*node = (*node)->right;
	else if ((*node)->left)
		*node = (*node)->left;
	else if ((*node)->children)
		*node = (*node)->children;
}

t_mt	*ft_mtdisconnect(t_mt **node)
{
	t_mt	*disconnected;

	if (!node || !(*node))
		return (NULL); // Retorna NULL si el nodo es inválido
	disconnected = *node;
	go_to_existing(node);
	disconnected = ft_connect_childrens(&disconnected);
	disconnected = ft_connect_parent(&disconnected);
	disconnected = ft_connect_siblings(&disconnected);
	return (disconnected); // Retorna el nodo desconectado
}
