/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:52:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/12 13:47:32 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*Swap the 2 first elements of the pile a*/
void	sa(t_pile **a, int print)
{
	t_pile	*head;
	t_pile	*ptr;

	head = (*a)->next;
	head->prev = (*a)->prev;
	head->next = *a;
	(*a)->prev = head;
	(*a)->next = (*a)->next->next;
	*a = head;
	if (print)
		printf("sa\n");
}

/*Swap the 2 first elements of the pile b*/
void	sb(t_pile **b, int print)
{
	t_pile	*head;
	t_pile	*ptr;

	head = (*b)->next;
	head->prev = (*b)->prev;
	head->next = *b;
	(*b)->prev = head;
	(*b)->next = (*b)->next->next;
	*b = head;
	if (print)
		printf("sb\n");
}

/*Swap the 2 first elements of the piles a and b*/
void	ss(t_pile **a, t_pile **b)
{
	sa(a, 0);
	sb(b, 0);
	printf("ss\n");
}