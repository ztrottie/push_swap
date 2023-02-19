/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:56:32 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/19 09:53:59 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_pile(t_pile *pile)
{
	t_pile	*ptr;
	t_pile	*tmp;

	ptr = pile;
	while(ptr->next != pile)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(ptr);
}

int	pile_add_end(int data, t_pile **pile)
{
	t_pile	*new;

	new = (t_pile *)ft_calloc(1, sizeof(t_pile));
	if (!new)
		return (1);
	new->data = data;
	new->prev = (*pile)->prev;
	(*pile)->prev->next = new;
	new->next = *pile;
	(*pile)->prev = new;
	return (0);
}

void	*free_all(t_structs *piles)
{
	if (piles->a)
		free_pile(piles->a);
	if (piles->b)
		free_pile(piles->b);
	free(piles);
	return (NULL);
}