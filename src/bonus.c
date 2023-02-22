/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:36:04 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/22 15:17:16 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include <unistd.h>

static void	add_commands_end(t_com **commands, char *str)
{
	t_com	*ptr;
	t_com	*new;

	ptr = *commands;
	while (ptr->next != NULL)
		ptr = ptr->next;
	new = (t_com *)ft_calloc(1, sizeof(t_com));
	if (!new)
		return ;
	new->data = str;
	new->next = NULL;
	ptr->next = new;
}

static void	get_commands(t_structs *piles)
{
	char	*str;
	t_com	*commands;

	piles->commands = (t_com *)ft_calloc(1, sizeof(t_com));
	piles->commands->data = get_next_line(0);
	piles->commands->next = NULL;
	str = get_next_line(0);
	while (str != NULL)
	{
		add_commands_end(&piles->commands, str);
		str = get_next_line(0);
		if (!ft_strncmp(str, "rra\n", 4))
			close(0);
	}
}

static void	do_op(t_structs *piles)
{
	t_com	*ptr;
	
	get_commands(piles);
	ptr = piles->commands;
	while (ptr != NULL)
	{
		if (ft_strncmp(ptr->data, "rra\n", 4))
			rra(&piles->a, 0);
	}
}

int	main(int argc, char **argv)
{
	t_structs	*piles;

	if (argc == 1)
		return (0);
	argv = argv_conv(&argc, argv);
	if (!argv)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (input_error(argc, argv))
		return (ft_putstr_fd("Error\n", 2), free(argv), 0);
	piles = (t_structs *)ft_calloc(1, sizeof(t_structs));
	if (!piles)
		return (ft_putstr_fd("Error\n", 2), 0);
	piles->total_count = argc;
	piles->a_count = argc;
	if (init_push_swap(argc, argv, piles))
		return (ft_putstr_fd("Error\n", 2), free(piles), free(argv), 0);
	do_op(piles);
	return (free_all(piles), 0);
}

