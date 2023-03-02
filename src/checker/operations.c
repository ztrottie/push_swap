/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:39:09 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/01 21:58:31 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	rotation_operation(char *command, t_structs *piles)
{
	if (ft_strncmp(command, "ra", 2) == 0)
		ra(&piles->a, 0);
	else if (ft_strncmp(command, "rb", 2) == 0)
		rb(&piles->b, 0);
	else if (ft_strncmp(command, "rr", 2) == 0)
		rr(&piles->a, &piles->b, 0);
}

void	reverse_rotation_operation(char *command, t_structs *piles)
{
	if (ft_strncmp(command, "rra", 3) == 0)
		rra(&piles->a, 0);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		rrb(&piles->b, 0);
	else if (ft_strncmp(command, "rrr", 3) == 0)
		rrr(&piles->a, &piles->b, 0);
}

void	swap_operation(char *command, t_structs *piles)
{
	if (ft_strncmp(command, "sa", 2) == 0)
		sa(&piles->a, piles->a_count, 0);
	else if (ft_strncmp(command, "sb", 2) == 0)
		sb(&piles->b, piles->b_count, 0);
	else if (ft_strncmp(command, "ss", 2) == 0)
		ss(piles, 0);
}

void	push_operation(char *command, t_structs *piles)
{
	if (ft_strncmp(command, "pa", 2) == 0)
		pa(piles, 0);
	else if (ft_strncmp(command, "pb", 2) == 0)
		pb(piles, 0);
}
