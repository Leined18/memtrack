/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 07:56:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_mtpop(t_mt **lst)
{
	t_mt	*tmp;
	t_mt	*mem;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	mem = chaosmatrix(0, 0, 1);
	ft_mtadd_back(&mem, ft_mtnew(tmp->data));
	free(tmp);
	tmp = NULL;
}
void	ft_mtpop_string(t_mt **lst, char *remove)
{
	t_mt	*current;
	t_mt	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp((char *)current->data, remove) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			ft_mtpop(&current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	ft_mtpop_number(t_mt **lst, int remove)
{
	t_mt	*current;
	t_mt	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (current->n == remove)
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			ft_mtpop(&current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	ft_mtpop_data(t_mt **lst, void *remove)
{
	t_mt	*current;
	t_mt	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (current->data == remove)
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			ft_mtpop(&current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
