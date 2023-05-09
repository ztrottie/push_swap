/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:52:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/09 10:14:39 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

static void	std_push(t_pile **a, t_pile **b)
{
	t_pile	*head_a;
	t_pile	*head_b;

	head_a = (*a)->next;
	head_a->prev = (*a)->prev;
	head_a->prev->next = head_a;
	head_b = (*a);
	head_b->next = (*b);
	head_b->prev = (*b)->prev;
	head_b->next->prev = head_b;
	head_b->prev->next = head_b;
	(*a) = head_a;
	(*b) = head_b;
}

static void	empty_push(t_pile **a, t_pile **b)
{
	t_pile	*head_a;
	t_pile	*head_b;

	head_a = (*a)->next;
	head_a->prev = (*a)->prev;
	head_a->prev->next = head_a;
	head_b = (*a);
	head_b->next = head_b;
	head_b->prev = head_b;
	(*a) = head_a;
	(*b) = head_b;
}

static void	last_push(t_pile **a, t_pile **b)
{
	t_pile	*head_b;

	head_b = (*a);
	head_b->next = (*b);
	head_b->prev = (*b)->prev;
	head_b->next->prev = head_b;
	head_b->prev->next = head_b;
	(*a) = NULL;
	(*b) = head_b;
}

/*send the first element of b on top of a*/
void	pa(t_structs *piles, int print)
{
	Ct_make_flag("pa", 1);
	if (!piles->b)
		return ;
	if (piles->a_count == 0)
		empty_push(&piles->b, &piles->a);
	else if (piles->b_count == 1)
		last_push(&piles->b, &piles->a);
	else
		std_push(&piles->b, &piles->a);
	piles->a_count++;
	piles->b_count--;
	if (print)
		ft_printf("pa\n");
}

/*send the first element of a on top of b*/
void	pb(t_structs *piles, int print)
{
	Ct_make_flag("pb", 1);
	if (!piles->a)
		return ;
	if (piles->b_count == 0)
		empty_push(&piles->a, &piles->b);
	else if (piles->a_count == 1)
		last_push(&piles->a, &piles->b);
	else
		std_push(&piles->a, &piles->b);
	piles->b_count++;
	piles->a_count--;
	if (print)
		ft_printf("pb\n");
}
