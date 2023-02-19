/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:04:06 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/19 14:45:30 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	block_sep(t_structs **piles, int block)
{
	while ((*piles)->nb_block_a[block - 1] > 0)
	{
		if ((*piles)->a->block == block)
		{
			pb(piles);
			(*piles)->nb_block_a[block - 1]--;
		}
		else
			ra(&(*piles)->a, 1);
	}
}	

void	block_init(t_structs **piles)
{
	t_pile	*ptr;

	ptr = (*piles)->a;
	while (ptr->block == 0)
	{
		ptr->block = ptr->data / (*piles)->block_sizes + 1;
		(*piles)->nb_block_a[ptr->block - 1]++;
		ptr = ptr->next;
	}
}

int	block_alloc(t_structs **piles)
{
	t_pile	*ptr;

	ptr = (*piles)->a;
	(*piles)->nb_block_a = ft_calloc(5, sizeof(int));
	(*piles)->nb_block_b = ft_calloc(5, sizeof(int));
	if (!(*piles)->nb_block_a || !(*piles)->nb_block_b)
	{
		ft_free((*piles)->nb_block_a);
		ft_free((*piles)->nb_block_b);
		return (1);
	}
	return (0);
}