/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:04:06 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/20 13:55:39 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	block_sep(t_structs *piles, int block)
{
	int	comp;

	comp = piles->block_sizes * block - piles->block_sizes / 2;
	while (piles->nb_block_a[block - 1] > 0)
	{
		if (piles->a->block == block)
		{
			pb(piles, 1);
			if (piles->b->data < comp && piles->a->block != block)
				rr(&piles->a, &piles->b, 1);
			else if (piles->b->data < comp && piles->a->block == block)
				rb(&piles->b, 1);
			piles->nb_block_a[block - 1]--;
		}
		else
			ra(&piles->a, 1);
	}
}	

void	block_init(t_structs *piles)
{
	t_pile	*ptr;

	ptr = piles->a;
	while (ptr->block == 0)
	{
		ptr->block = ptr->data / piles->block_sizes + 1;
		piles->nb_block_a[ptr->block - 1]++;
		ptr = ptr->next;
	}
}

void	block_count(t_structs *piles)
{
	if (piles->total_count <= 10)
		piles->nb_total_block = piles->total_count;
	else
		piles->nb_total_block = 5;
}

int	block_alloc(t_structs *piles)
{
	piles->nb_block_a = ft_calloc(piles->nb_total_block + 1, sizeof(int));
	piles->nb_block_b = ft_calloc(piles->nb_total_block + 1, sizeof(int));
	if (!piles->nb_block_a || !piles->nb_block_b)
	{
		ft_free(piles->nb_block_a);
		ft_free(piles->nb_block_b);
		return (1);
	}
	return (0);
}
