/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtexchange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:14:20 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/19 12:17:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/*
It exchanges the position of the current node with the node in the direction
specified. If the current node is the root or the node in the direction is the
root, it swaps the root with the node in the opposite direction.
*/
int	ft_mtexchange(t_mt **lst, t_mt *curr, t_direction direction)
{
	t_mt	*prev;
	t_mt	*next;
	t_mt	*n_direc;
	int		oposite;

	if (!curr || !curr->vect[direction])
		return (1);
	n_direc = curr->vect[direction];
	if (*lst == curr || *lst == n_direc)
		ft_mtswap(lst, RIGHT);
	else
	{
		oposite = ft_mtoposite_direction(direction);
		next = n_direc->vect[direction];
		prev = curr->vect[oposite];
		curr->vect[direction] = next;
		n_direc->vect[direction] = curr;
		n_direc->vect[oposite] = prev;
		curr->vect[oposite] = n_direc;
		if (prev)
			prev->vect[direction] = n_direc;
		if (next)
			next->vect[oposite] = curr;
	}
	return (0);
}
