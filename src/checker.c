/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:36:04 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/24 14:17:00 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include <fcntl.h>

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
	int		fd;
	t_com	*commands;

	fd = open("text.txt", O_RDONLY);
	piles->commands = (t_com *)ft_calloc(1, sizeof(t_com));
	piles->commands->data = get_next_line(fd);
	piles->commands->next = NULL;
	str = get_next_line(fd);
	while (str != NULL)
	{
		add_commands_end(&piles->commands, str);
		str = get_next_line(fd);
	}
}

static int	do_op(t_structs *piles)
{
	t_com	*ptr;
	
	get_commands(piles);
	ptr = piles->commands;
	while (ptr != NULL)
	{
		if (ft_strncmp(ptr->data, "rra\n", 4))
			rra(&piles->a, 0);
		else if (ft_strncmp(ptr->data, "ra\n", 3))
			ra(&piles->a, 0);
		else if (ft_strncmp(ptr->data, "pa\n", 3))
			pa(piles, 0);
		else if (ft_strncmp(ptr->data, "sa\n", 3))
			sa(&piles->a, piles->a_count, 0);
		else if (ft_strncmp(ptr->data, "rrb\n", 4))
			rrb(&piles->b, 0);
		else if (ft_strncmp(ptr->data, "rb\n", 3))
			rb(&piles->b, 0);
		else if (ft_strncmp(ptr->data, "sb\n", 3))
			sb(&piles->b, piles->b_count, 0);
		else if (ft_strncmp(ptr->data, "pb\n", 3))
			pb(piles, 0);
		else if (ft_strncmp(ptr->data, "ss\n", 3))
			ss(piles, 0);
		else if (ft_strncmp(ptr->data, "rr\n", 3))
			rr(&piles->a, &piles->b, 0);
		else if (ft_strncmp(ptr->data, "rrr\n", 4))
			rrr(&piles->a, &piles->b, 0);
		else 
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_structs	*piles;
	char		**new_argv;

	piles = (t_structs *)ft_calloc(1, sizeof(t_structs));
	if (!piles)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (argc == 1)
		return (0);
	new_argv = argv_conv(&argc, argv, piles);
	if (!new_argv)
		return (ft_putstr_fd("Error\n", 2), free_all(piles, new_argv), 0);
	if (input_error(argc, new_argv))
		return (ft_putstr_fd("Error\n", 2), free_all(piles, new_argv), 0);
	piles->total_count = argc;
	piles->a_count = argc;
	if (init_push_swap(argc, new_argv, piles))
		return (ft_putstr_fd("Error\n", 2), free_all(piles, new_argv), 0);
	do_op(piles);
	return (free_all(piles, new_argv), 0);
}
