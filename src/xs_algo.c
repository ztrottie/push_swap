/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xs_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:56:59 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/16 11:51:12 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_sort_a(t_structs **piles)
{
	int	first;
	int second;

	first = (*piles)->a->data;
	second = (*piles)->a->next->data;
	if (first > second)
		sa(&(*piles)->a, (*piles)->a_count, 1);
}

void	two_sort_b(t_structs **piles)
{
	int	first;
	int second;

	first = (*piles)->b->data;
	second = (*piles)->b->next->data;
	if (first > second)
		sb(&(*piles)->b, (*piles)->b_count, 1);
}

void	three_sort_b(t_structs **piles)
{
	int	first;
	int	second;
	int	third;

	first = (*piles)->b->data;
	second = (*piles)->b->next->data;
	third = (*piles)->b->prev->data;
	if (first < second && first < third)
		rb(&(*piles)->b, 1);
	if (second < first && second < third)
		rrb(&(*piles)->b, 1);
	if (first < second && first > third)
		sb(&(*piles)->b, (*piles)->b_count, 1);
}

void	three_sort_a(t_structs **piles)
{
	if ((*piles)->a->data > (*piles)->a->next->data && (*piles)->a->data > (*piles)->a->prev->data)
		ra(&(*piles)->a, 1);
	if ((*piles)->a->next->data > (*piles)->a->data && (*piles)->a->next->data > (*piles)->a->prev->data)
		rra(&(*piles)->a, 1);
	if ((*piles)->a->data > (*piles)->a->next->data && (*piles)->a->prev->data > (*piles)->a->data)
		sa(&(*piles)->a, (*piles)->a_count, 1);
}

void	xs_algo(t_structs **piles)
{
	if ((*piles)->total_count > 3)
	{
		while ((*piles)->b_count != 3)
		{
			if ((*piles)->a->data <= 3)
				pb(piles);
			else
				ra(&(*piles)->a, 1);
		}
		three_sort_b(piles);
	}
	if ((*piles)->a_count == 2)
		two_sort_a(piles);
	else if ((*piles)->a_count == 3)
		three_sort_a(piles);
	while ((*piles)->b_count > 0)
		pa(piles);
}