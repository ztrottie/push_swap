/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:37:34 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/15 18:58:37 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	algo_selection(t_structs **piles)
{
	if ((*piles)->total_count == 2)
		sa(&(*piles)->a, (*piles)->a_count, 1);
	if ((*piles)->total_count > 2 && (*piles)->total_count < 7)
		xs_algo(piles);
}

int	main(int argc, char **argv)
{
	t_structs *piles;

	piles = NULL;
	if (input_error(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 0);
	piles = (t_structs *)malloc(sizeof(t_structs));
	if (!piles)
		return (ft_putstr_fd("Error\n", 2), 0);
	piles->total_count = argc - 1;
	piles->a_count = argc - 1;
	piles->b_count = 0;
	if (init_push_swap(argc, argv, &piles))
		return (ft_putstr_fd("Error\n", 2), free(piles), 0);
	if (sort_checker(&piles->a))
		algo_selection(&piles);
	return (free_all(piles), 0);
}