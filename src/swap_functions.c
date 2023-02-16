/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:52:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/15 15:52:07 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	std_swap(t_pile **a)
{
	t_pile	*head;

	head = (*a)->next;
	head->prev = (*a)->prev;
	head->prev->next = head;
	head->next = (*a);
	(*a)->prev = head;
	(*a)->next = (*a)->next->next;
	(*a)->next->prev = (*a);
	(*a) = head;
}

/*Swap the 2 first elements of the pile a*/
void	sa(t_pile **a, int count, int print)
{
	t_pile	*head;
	
	if (count > 2)
		std_swap(a);
	else
		ra(a, 0);
	if (print)
		printf("sa\n");
}

/*Swap the 2 first elements of the pile b*/
void	sb(t_pile **b, int count, int print)
{
	t_pile	*head;
	
	if (count > 2)
		std_swap(b);
	else
		rb(b, 0);
	if (print)
		printf("sb\n");
}

/*Swap the 2 first elements of the piles a and b*/
void	ss(t_structs **piles)
{
	sa(&(*piles)->a, (*piles)->a_count, 0);
	sa(&(*piles)->b, (*piles)->b_count, 0);
	printf("ss\n");
}