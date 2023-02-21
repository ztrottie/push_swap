/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xs_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:56:59 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/21 12:29:39 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	xs_algo(t_structs *piles)
{
	if (piles->total_count > 3)
	{
		while (piles->a_count > 3)
		{
			if (piles->a->data <= piles->total_count - 3)
				pb(piles);
			else
				ra(&piles->a, 1);
		}
	}
	if (piles->b_count == 2)
		two_sort_b(piles);
	else if (piles->b_count == 3)
		three_sort_b(piles);
	if (piles->a_count == 2)
		two_sort_a(piles);
	else if (piles->a_count == 3)
		three_sort_a(piles);
	while (piles->b_count > 0)
		pa(piles);
}