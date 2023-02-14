/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:37:34 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/14 16:40:08 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

static t_structs	*init_push_swap(int argc, char **argv, t_structs *piles)
{
	int	*tmp;

	tmp = (int *)ft_calloc(argc, sizeof(int));
	if (!tmp)
		return (NULL);
		
}

int	main(int argc, char **argv)
{
	t_structs *piles;
	
	if (input_error(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 0);
	piles = (t_structs *)malloc(sizeof(t_structs));
	if (!piles)
		return (ft_putstr_fd("Error\n", 2), 0);
	piles = init_push_swap(argc, argv, piles);
	if (!piles)
		return (ft_putstr_fd("Error\n", 2), 0);
	return (free(piles), 0);
}