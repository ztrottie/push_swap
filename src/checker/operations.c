/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:39:09 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/13 14:39:34 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	rotation_operation(char *command, t_structs *piles)
{
	if (ft_strncmp(command, "ra\n", 3) == 0)
		ra(&piles->a, 0);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rb(&piles->b, 0);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rr(&piles->a, &piles->b, 0);
	else
		return (1);
	return(0);
}

int	reverse_rotation_operation(char *command, t_structs *piles)
{
	if (ft_strncmp(command, "rra\n", 4) == 0)
		rra(&piles->a, 0);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		rrb(&piles->b, 0);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		rrr(&piles->a, &piles->b, 0);
	else
		return (1);
	return(0);
}

int	swap_operation(char *command, t_structs *piles)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		sa(&piles->a, piles->a_count, 0);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		sb(&piles->b, piles->b_count, 0);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ss(piles, 0);
	else
		return (1);
	return(0);
}

int	push_operation(char *command, t_structs *piles)
{
	if (ft_strncmp(command, "pa\n", 3) == 0)
		pa(piles, 0);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		pb(piles, 0);
	else
		return (1);
	return(0);
}
