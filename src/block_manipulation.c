/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:04:06 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/21 18:26:38 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	block_sep(t_structs *piles, int block)
{
	int block1;
	int	block2;

	block1 = piles->nb_block_a[block - 1];
	block2 = piles->nb_block_a[block - 2];
	while (block1 > 0 || block2 > 0)
	{
		if (piles->a->block == block || piles->a->block == block - 1)
		{
			pb(piles);
			if (piles->b->block == block)
				block1--;
			if (piles->b->block == block - 1)
				block2--;
			if (piles->b->block == block - 1 && piles->a->block != block && piles->a->block != block - 1)
				rr(&piles->a, &piles->b);
			else if (piles->b->block == block - 1)
				rb(&piles->b, 1);
		}
		else
			ra(&piles->a, 1);
	}
	piles->nb_block_a[block - 1] = block1;
	piles->nb_block_a[block - 2] = block2;
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
	else if (piles->total_count <= 100)
		piles->nb_total_block = 10;
	else
		piles->nb_total_block = 10;
}

int	block_alloc(t_structs *piles)
{
	t_pile	*ptr;

	ptr = piles->a;
	piles->nb_block_a = ft_calloc(piles->nb_total_block, sizeof(int));
	piles->nb_block_b = ft_calloc(piles->nb_total_block, sizeof(int));
	if (!piles->nb_block_a || !piles->nb_block_b)
	{
		ft_free(piles->nb_block_a);
		ft_free(piles->nb_block_b);
		return (1);
	}
	return (0);
}