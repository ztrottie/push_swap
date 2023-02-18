/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:26:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/18 13:52:07 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	block_separation()
{
	
}

void	ultimate_sort(t_structs **piles)
{
	(*piles)->block_sizes = (*piles)->total_count * 20 / 100;

}