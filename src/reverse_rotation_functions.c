/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:37:45 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/22 12:58:25 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*Rotate downwards the pile a*/
void	rra(t_pile **a, int print)
{
	*a = (*a)->prev;
	if (print)
		ft_printf("rra\n");
}

/*Rotate downwards the pile b*/
void	rrb(t_pile **b, int print)
{
	*b = (*b)->prev;
	if (print)
		ft_printf("rrb\n");
}

/*Rotate downwards the piles a and b*/
void	rrr(t_pile **a, t_pile **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}
