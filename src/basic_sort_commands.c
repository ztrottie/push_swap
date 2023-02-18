/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:29 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/18 11:46:47 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_sort_a(t_structs **piles)
{
	if ((*piles)->a->data > (*piles)->a->next->data)
		sa(&(*piles)->a, (*piles)->a_count, 1);
}

void	two_sort_b(t_structs **piles)
{
	if ((*piles)->b->data < (*piles)->b->next->data)
		sb(&(*piles)->b, (*piles)->b_count, 1);
}

void	three_sort_b(t_structs **piles)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*third;

	first = (*piles)->b;
	second = (*piles)->b->next;
	third = (*piles)->b->prev;
	if (first->data < second->data && first->data < third->data)
	{
		rb(&(*piles)->b, 1);
		three_sort_b(piles);
	}
	else if (second->data < first->data && second->data < third->data)
	{
		rrb(&(*piles)->b, 1);
		three_sort_b(piles);
	}
	else if (second->data > first->data && second->data > third->data)
		sb(&(*piles)->b, (*piles)->a_count, 1);
}

void	three_sort_a(t_structs **piles)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*third;

	first = (*piles)->a;
	second = (*piles)->a->next;
	third = (*piles)->a->prev;
	if (first->data > third->data && first->data > second->data)
	{
		ra(&(*piles)->a, 1);
		three_sort_a(piles);
	}
	else if (second->data > first->data && second->data > third->data)
	{
		rra(&(*piles)->a, 1);
		three_sort_a(piles);
	}
	else if (first->data > second->data && first->data < third->data)
		sa(&(*piles)->a, (*piles)->a_count, 1);
}