/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:26:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/21 18:26:58 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_next(t_structs *piles)
{
	int		up;
	int		down;
	t_pile	*ptr;

	ptr = piles->b;
	up = 0;
	while (ptr->data < piles->a->prev->data)
	{
		up++;
		ptr = ptr->next;
	}
	ptr = piles->b;
	down = 0;
	while (ptr->data < piles->a->prev->data)
	{
		down++;
		ptr = ptr->prev;
	}
	if (up < down)
		return (up);
	return (-down);
}

void	place_next(t_structs *piles)
{
	int	next;

	next = find_next(piles);
	while (next != 0)
	{
		if (next < 0)
		{
			rrb(&piles->b, 1);
			next++;
		}
		else
		{
			rb(&piles->b, 1);
			next--;
		}
	}
}

void	final_sort(t_structs *piles)
{
	int	nb;
	
	nb = piles->total_count - 1;
	while (piles->a_count != piles->total_count)
	{
		if (piles->b->data == nb)
		{
			pa(piles);
			nb--;
		}
		else if (piles->a->prev->data == nb)
		{
			nb--;
			rra(&piles->a, 1);
		}
		else if (piles->b->data > piles->a->prev->data || piles->a->prev->data == piles->total_count)
		{
			pa(piles);
			ra(&piles->a, 1);
		}
		else
			place_next(piles);
	}
	while (piles->a->data != 1)
		rra(&piles->a, 1);
}

void	ultimate_sort(t_structs *piles)
{
	int 	i;

	i = 2;
	block_count(piles);
	piles->block_sizes = piles->total_count / piles->nb_total_block;
	if (block_alloc(piles))
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	block_init(piles);
	while (i <= piles->nb_total_block)
	{
		block_sep(piles, i);
		i = i + 2;
	}
	ft_free(piles->nb_block_a);
	ft_free(piles->nb_block_b);
	final_sort(piles);
}