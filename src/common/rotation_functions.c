/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:15:20 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/17 12:35:04 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

/*Rotate the pile a upwards*/
void	ra(t_pile **a, int print)
{
	if (!*a)
		return ;
	*a = (*a)->next;
	if (print)
		ft_printf("ra\n");
}

/*Rotate the pile b upwards*/
void	rb(t_pile **b, int print)
{
	if (!*b)
		return ;
	*b = (*b)->next;
	if (print)
		ft_printf("rb\n");
}

/*Rotate the piles a and b upwards*/
void	rr(t_pile **a, t_pile **b, int print)
{
	if (!*a || !*b)
		return ;
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_printf("rr\n");
}
