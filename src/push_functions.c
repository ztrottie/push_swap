/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:52:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/12 13:48:02 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_structs	*pa(t_structs *piles)
{
	t_pile	*head_a;
	t_pile	*head_b;

	head_a = piles->b;
	head_b = piles->b->next;
	head_b->prev = piles->b->prev;
	head_b->prev->next = head_b;
	piles->b = head_b;
	head_a->prev = piles->a->prev;
	head_a->prev->next = head_a;
	head_a->next = piles->a;
	head_a->next->prev = head_a;
	piles->a = head_a;
	return (printf("pa\n"), piles);
}

t_structs	*pb(t_structs *piles)
{
	t_pile	*head_a;
	t_pile	*head_b;

	head_b = piles->a;
	head_a = piles->a->next;
	head_a->prev = piles->a->prev;
	head_a->prev->next = head_a;
	piles->a = head_a;
	head_b->prev = piles->b->prev;
	head_b->prev->next = head_b;
	head_b->next = piles->b;
	head_b->next->prev = head_b;
	piles->b = head_b;
	return (printf("pb\n"), piles);
}