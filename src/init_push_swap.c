/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:57:01 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/15 11:52:51 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	index_nb(int *array, int index, int len)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (array[i] < array[index])
			count++;
		i++;
	}
	return (count + 1);
}

static t_pile	*init_a(int argc, char **argv)
{
	int		*tmp;
	int		i;
	t_pile	*a;

	tmp = temp_array(argc, argv);
	a = (t_pile *)malloc(sizeof(t_pile));
	if (!a || !tmp)
		return (NULL);
	while (i < argc - 1)
	{
		pile_add_end(index_nb(tmp, i, argc - 1), a);
		i++;
	}
	return (a);
}

int	init_push_swap(int argc, char **argv, t_structs *piles)
{
	piles->a = init_a(argc, argv);
	if (!piles->a)
		return (1);
}