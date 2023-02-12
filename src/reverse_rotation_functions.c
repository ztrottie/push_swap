/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:37:45 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/12 13:47:48 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*Rotate downwards the pile a*/
void	rra(t_pile **a, int print)
{
	*a = (*a)->prev;
	if (print)
		printf("rra\n");
}

/*Rotate downwards the pile b*/
void	rrb(t_pile **b, int print)
{
	*b = (*b)->prev;
	if (print)
		printf("rrb\n");
}

/*Rotate downwards the piles a and b*/
void	rrr(t_pile **a, t_pile **b)
{
	rra(a, 0);
	rrb(b, 0);
	printf("rrr\n");
}