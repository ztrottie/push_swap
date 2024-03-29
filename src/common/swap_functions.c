/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:52:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/09 10:16:18 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

static void	std_swap(t_pile **a)
{
	t_pile	*head;
	t_pile	*ptr;

	ptr = (*a);
	head = (*a)->next;
	head->prev = ptr->prev;
	ptr->next = head->next;
	head->next = ptr;
	ptr->prev = head;
	ptr->next->prev = ptr;
	head->prev->next = head;
	(*a) = head;
}

/*Swap the 2 first elements of the pile a*/
void	sa(t_pile **a, int count, int print)
{
	Ct_make_flag("sa", 1);
	if (!*a)
		return ;
	if (count > 2)
		std_swap(a);
	else
		ra(a, 0);
	if (print)
		ft_printf("sa\n");
}

/*Swap the 2 first elements of the pile b*/
void	sb(t_pile **b, int count, int print)
{
	Ct_make_flag("sb", 1);
	if (!*b)
		return ;
	if (count > 2)
		std_swap(b);
	else
		rb(b, 0);
	if (print)
		ft_printf("sb\n");
}

/*Swap the 2 first elements of the piles a and b*/
void	ss(t_structs *piles, int print)
{
	Ct_make_flag("ss", 1);
	if (!piles->a || !piles->b)
		return ;
	sa(&piles->a, piles->a_count, 0);
	sb(&piles->b, piles->b_count, 0);
	if (print)
		ft_printf("ss\n");
}
