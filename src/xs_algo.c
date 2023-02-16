/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xs_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:56:59 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/15 20:05:41 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	xs_algo(t_structs **piles)
{
	while ((*piles)->a_count > 3)
	{
		if ((*piles)->a->data <= 3)
			pb(piles);
		else
			ra(&(*piles)->a, 1);
	}
}