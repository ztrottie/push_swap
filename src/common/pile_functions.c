/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:56:32 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/28 11:10:02 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_pile(t_pile *pile)
{
	t_pile	*ptr;
	t_pile	*tmp;

	ptr = pile;
	while (ptr->next != pile)
	{
		tmp = ptr->next;
		ft_free(ptr);
		ptr = tmp;
	}
	ft_free(ptr);
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

void	*free_all(t_structs *piles, char **argv)
{
	int	i;

	if (piles->a != NULL)
		free_pile(piles->a);
	if (piles->b != NULL)
		free_pile(piles->b);
	i = 0;
	if (piles->temp)
	{
		while (argv[i])
			ft_free((void *)argv[i++]);
		ft_free((void **)argv);
	}
	ft_free(piles);
	return (NULL);
}
