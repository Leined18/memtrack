/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdisconnect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:01:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 20:55:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	*ft_mtdisconnect_left(t_mt **node)
{
	t_mt	*disconnected;

	if (!node || !(*node))
		return (NULL); // Retorna NULL si el nodo es inválido
	disconnected = (*node)->left;
	if (disconnected)
		disconnected->right = NULL;
	// Desconecta el nodo derecho del nodo izquierdo
	(*node)->left = NULL;  // Desconecta el nodo izquierdo
	return (disconnected); // Retorna el nodo desconectado
}

void	*ft_mtdisconnect_right(t_mt **node)
{
	t_mt	*disconnected;

	if (!node || !(*node))
		return (NULL);             // Retorna NULL si el nodo es inválido
	disconnected = (*node)->right; // Guarda el nodo derecho
	if (disconnected)
		disconnected->left = NULL; // Desconecta el nodo izquierdo
	(*node)->right = NULL;         // Desconecta el nodo derecho
	return (disconnected);         // Retorna el nodo desconectado
}

void	*ft_mtdisconnect_parent(t_mt **node)
{
	t_mt	*disconnected;

	if (!node || !(*node))
		return (NULL);              // Retorna NULL si el nodo es inválido
	disconnected = (*node)->parent; // Guarda el nodo padre
	if (disconnected)
		disconnected->children = NULL; // Desconecta el nodo hijo
	(*node)->parent = NULL;            // Desconecta el nodo padre
	return (disconnected);             // Retorna el nodo desconectado
}

void	*ft_mtdisconnect_child(t_mt **node)
{
	t_mt	*disconnected;

	if (!node || !(*node))
		return (NULL);                // Retorna NULL si el nodo es inválido
	disconnected = (*node)->children; // Guarda el nodo hijo
	if (disconnected)
		disconnected->parent = NULL; // Desconecta el nodo padre
	(*node)->children = NULL;        // Desconecta el nodo hijo
	return (disconnected);           // Retorna el nodo desconectado
}

void	*ft_mtconnect_left(t_mt **node, t_mt *left)
{
	t_mt	*disconnected;

	if (!node || !(*node))
		return (NULL);            // Retorna NULL si el nodo es inválido
	disconnected = (*node)->left; // Guarda el nodo izquierdo
	(*node)->left = left;         // Conecta el nodo izquierdo
	if ((*node)->left)
		(*node)->left->right = *node; // Conecta el nodo derecho
	if (disconnected)
		disconnected->right = NULL; // Desconecta el nodo derecho
	return (disconnected);          // Retorna el nodo desconectado
}

void	*ft_mtconnect_right(t_mt **node, t_mt *right)
{
	t_mt	*disconnected;

	if (!node || !(*node))
		return (NULL);             // Retorna NULL si el nodo es inválido
	disconnected = (*node)->right; // Guarda el nodo derecho
	(*node)->right = right;        // Conecta el nodo derecho
	if ((*node)->right)
		(*node)->right->left = *node; // Conecta el nodo izquierdo
	if (disconnected)
		disconnected->left = NULL; // Desconecta el nodo izquierdo
	return (disconnected);         // Retorna el nodo desconectado
}

void	*ft_mtconnect_parent(t_mt **node, t_mt *parent)
{
	t_mt	*disconnected;

	if (!node || !(*node))
		return (NULL);              // Retorna NULL si el nodo es inválido
	disconnected = (*node)->parent; // Guarda el nodo padre
	(*node)->parent = parent;       // Conecta el nodo padre
	if ((*node)->parent)
		(*node)->parent->children = *node; // Conecta el nodo hijo
	if (disconnected)
		disconnected->children = NULL; // Desconecta el nodo hijo
	return (disconnected);             // Retorna el nodo desconectado
}

void	*ft_mtconnect_child(t_mt **node, t_mt *child)
{
	t_mt	*disconnected;
	t_mt	*tmp;

	if (!node || !(*node))
		return (NULL); // Retorna NULL si el nodo es inválido
	disconnected = (*node)->children;
	(*node)->children = child;
	if ((*node)->children)
		(*node)->children->parent = *node;
	if (disconnected)
		disconnected->parent = NULL;
	tmp = NULL;
	tmp = ft_mtfirst(child);
	while (tmp && tmp->right)
	{
		tmp = tmp->right;
		tmp->parent = *node;
	}
	return (disconnected); // Retorna el nodo desconectado
}

void	ft_mtmove(t_mt **node)
{
	if (!node || !(*node))
		return ;
	if ((*node)->left)
		(*node) = (*node)->left;
	else if ((*node)->right)
		(*node) = (*node)->right;
	else if ((*node)->parent)
		(*node) = (*node)->parent;
	else if ((*node)->children)
		(*node) = (*node)->children;
}

void	ft_mtmove_left(t_mt **node)
{
	if (!node || !(*node))
		return ;
	if ((*node)->left)
		(*node) = (*node)->left;
}

void	ft_mtmove_right(t_mt **node)
{
	if (!node || !(*node))
		return ;
	if ((*node)->right)
		(*node) = (*node)->right;
}

void	ft_mtmove_parent(t_mt **node)
{
	if (!node || !(*node))
		return ;
	if ((*node)->parent)
		(*node) = (*node)->parent;
}

void	ft_mtmove_child(t_mt **node)
{
	if (!node || !(*node))
		return ;
	if ((*node)->children)
		(*node) = (*node)->children;
}

t_mt	*ft_mtdisconnect(t_mt **node)
{
	t_mt	*disconnected;
	t_mt	*left;
	t_mt	*right;
	t_mt	*parent;
	t_mt	*child;
	t_mt	*void_node;

	left = NULL;
	right = NULL;
	parent = NULL;
	child = NULL;
	if (!node || !(*node))
		return (NULL);
	disconnected = *node;
	left = ft_mtdisconnect_left(&disconnected);
	right = ft_mtdisconnect_right(&disconnected);
	parent = ft_mtdisconnect_parent(&disconnected);
	child = ft_mtdisconnect_child(&disconnected);
	void_node = ft_mtnew(NULL, NULL, 0);
	ft_mtconnect_child(&void_node, child);
	ft_mtconnect_parent(&void_node, parent);
	ft_mtconnect_left(&void_node, left);
	ft_mtconnect_right(&void_node, right);
	(*node) = void_node;
	return (disconnected);
}
