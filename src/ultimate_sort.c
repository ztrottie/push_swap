/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:26:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/19 14:12:58 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ultimate_sort(t_structs **piles)
{
	int 	i;

	i = 0;
	(*piles)->block_sizes = (*piles)->total_count * 20 / 100;
	if (block_alloc(piles))
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	block_init(piles);
	block_sep(piles, 1);
	block_sep(piles, 2);
	block_sep(piles, 3);
	block_sep(piles, 4);
	block_sep(piles, 5);
}