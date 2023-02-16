/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:37:34 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/16 11:11:17 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	algo_selection(t_structs **piles)
{
	if ((*piles)->total_count == 2)
		two_sort_a(piles);
	if ((*piles)->total_count > 2 && (*piles)->total_count < 7)
		xs_algo(piles);
}

int	main(int argc, char **argv)
{
	t_structs *piles;

	piles = NULL;
	if (argc == 1)
		return (0);
	argv = argv_conv(&argc, argv);
	if (!argv)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (input_error(argc, argv))
		return (ft_putstr_fd("Error\n", 2), free(argv), 0);
	piles = (t_structs *)malloc(sizeof(t_structs));
	if (!piles)
		return (ft_putstr_fd("Error\n", 2), 0);
	piles->total_count = argc;
	piles->a_count = argc;
	piles->b_count = 0;
	if (init_push_swap(argc, argv, &piles))
		return (ft_putstr_fd("Error\n", 2), free(piles), free(argv), 0);
	if (sort_checker(&piles->a))
		algo_selection(&piles);
	return (free_all(piles), 0);
}