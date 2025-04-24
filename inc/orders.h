/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:12:59 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:24:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDERS_H
# define ORDERS_H

# include "box.h"
# include "builder.h"
# include "factory.h"
# include "libft.h"

typedef enum e_sys_order
{
	ORDER_NONE,
	ORDER_BUILD,
	ORDER_DESTROY,
	ORDER_DESTROY_DATA,
	ORDER_DESTROY_ALL,
	ORDER_VALIDATE,
	ORDER_GET,
	ORDER_UPDATE,
	ORDER_REPORT,
	ORDER_COUNT // ← cantidad total
}			t_sys_order;


