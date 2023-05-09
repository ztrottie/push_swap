/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:37:45 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/09 10:15:14 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

/*Rotate downwards the pile a*/
void	rra(t_pile **a, int print)
{
	Ct_make_flag("rra", 1);
	if (!*a)
		return ;
	*a = (*a)->prev;
	if (print)
		ft_printf("rra\n");
}

/*Rotate downwards the pile b*/
void	rrb(t_pile **b, int print)
{
	Ct_make_flag("rrb", 1);
	if (!*b)
		return ;
	*b = (*b)->prev;
	if (print)
		ft_printf("rrb\n");
}

/*Rotate downwards the piles a and b*/
void	rrr(t_pile **a, t_pile **b, int print)
{
	Ct_make_flag("rrr", 1);
	if (!*a || !*b)
		return ;
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}
