/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:37:34 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/28 12:43:48 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	algo_selection(t_structs *piles)
{
	if (piles->total_count == 2)
		two_sort_a(piles);
	if (piles->total_count > 2 && piles->total_count < 7)
		xs_algo(piles);
	else
		ultimate_sort(piles);
}

int	main(int argc, char **argv)
{
	t_structs	*piles;
	char		**new_argv;

	piles = (t_structs *)ft_calloc(1, sizeof(t_structs));
	if (!piles)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (argc == 1)
		return (0);
	new_argv = argv_conv(&argc, argv, piles);
	if (!new_argv)
		return (ft_putstr_fd("Error\n", 2), free_all(piles, new_argv), 0);
	if (input_error(argc, new_argv))
		return (ft_putstr_fd("Error\n", 2), free_all(piles, new_argv), 0);
	piles->total_count = argc;
	piles->a_count = argc;
	if (init_push_swap(argc, new_argv, piles))
		return (ft_putstr_fd("Error\n", 2), free_all(piles, new_argv), 0);
	if (sort_checker(&piles->a))
		algo_selection(piles);
	return (free_all(piles, new_argv), 0);
}
