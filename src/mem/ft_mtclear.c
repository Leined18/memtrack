/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/12 16:29:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/**
 * ft_mtclear - Libera la memoria de la lista.
 * @lst: Lista a liberar.
 * tmp->free_data(&tmp->data); libera segun free_data
 */
static void	ft_mtclear_children(t_mt **child);
static void	ft_mtclear_left(t_mt **left);
static void	ft_mtclear_right(t_mt **right);
static void	ft_mtclear_parent(t_mt **parent);

void	ft_mtclear(t_mt **lst)
{
	if (!*lst || !lst)
		return ;
	(*lst)->aux = (*lst)->parent;
	if ((*lst)->parent)
		ft_mtclear_parent(&(*lst)->parent);
	if ((*lst)->right)
		ft_mtclear_right(&(*lst)->right);
	if ((*lst)->left)
		ft_mtclear_left(&(*lst)->left);
	if ((*lst)->children)
		ft_mtclear_children(&(*lst)->children);
	if (*lst)
	{
		if ((*lst)->values.to_free)
		{
			if ((*lst)->free_data)
				(*lst)->free_data(&(*lst)->data);
		}
		if ((*lst)->key)
			free((*lst)->key);
		free_null((void **)lst);
	}
}

static void	ft_mtclear_children(t_mt **child)
{
	(*child)->parent = NULL;
	ft_mtclear(child);
}

static void	ft_mtclear_left(t_mt **left)
{
	if ((*left)->right->aux == (*left)->parent
		|| (*left)->right->aux == (*left)->aux)
		(*left)->parent = NULL;
	(*left)->right = NULL;
	ft_mtclear(left);
}

static void	ft_mtclear_right(t_mt **right)
{
	if ((*right)->left->aux == (*right)->parent
		|| (*right)->left->aux == (*right)->aux)
		(*right)->parent = NULL;
	(*right)->left = NULL;
	ft_mtclear(right);
}

static void	ft_mtclear_parent(t_mt **parent)
{
	(*parent)->children = NULL;
	ft_mtclear(parent);
}
