/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:15:20 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/09 10:15:45 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

/*Rotate the pile a upwards*/
void	ra(t_pile **a, int print)
{
	Ct_make_flag("ra", 1);
	if (!*a)
		return ;
	*a = (*a)->next;
	if (print)
		ft_printf("ra\n");
}

/*Rotate the pile b upwards*/
void	rb(t_pile **b, int print)
{
	Ct_make_flag("rb", 1);
	if (!*b)
		return ;
	*b = (*b)->next;
	if (print)
		ft_printf("rb\n");
}

/*Rotate the piles a and b upwards*/
void	rr(t_pile **a, t_pile **b, int print)
{
	Ct_make_flag("rr", 1);
	if (!*a || !*b)
		return ;
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_printf("rr\n");
}
