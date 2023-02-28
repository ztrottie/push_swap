/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:02:12 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/28 18:22:22 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include <unistd.h>
#include <fcntl.h>

static void	add_commands_end(t_commands **commands, char *str)
{
	t_commands	*ptr;
	t_commands	*new;

	ptr = *commands;
	while (ptr->next != NULL)
		ptr = ptr->next;
	new = (t_commands *)ft_calloc(1, sizeof(t_commands));
	new->data = str;
	new->next = NULL;
	ptr->next = new;
}

static void	do_op(t_commands *commands, t_structs *piles)
{
	t_commands	*ptr;

	ptr = commands;
	while (ptr != NULL)
	{
		if (ft_strncmp(ptr->data, "ra", 2) == 0)
			ra(&piles->a, 0);
		else if (ft_strncmp(ptr->data, "rb", 2) == 0)
			rb(&piles->b, 0);
		else if (ft_strncmp(ptr->data, "sa", 2) == 0)
			sa(&piles->a, piles->a_count, 0);
		else if (ft_strncmp(ptr->data, "sb", 2) == 0)
			sb(&piles->b, piles->b_count, 0);
		else if (ft_strncmp(ptr->data, "ss", 2) == 0)
			ss(piles, 0);
		else if (ft_strncmp(ptr->data, "rra", 3) == 0)
			rra(&piles->a, 0);
		else if (ft_strncmp(ptr->data, "rrb", 3) == 0)
			rrb(&piles->b, 0);
		else if (ft_strncmp(ptr->data, "rrr", 3) == 0)
			rrr(&piles->a, &piles->b, 0);
		else if (ft_strncmp(ptr->data, "pa", 2) == 0)
			pa(piles, 0);
		else if (ft_strncmp(ptr->data, "pb", 2) == 0)
			pb(piles, 0);
		else if (ft_strncmp(ptr->data, "rr", 2) == 0)
			rr(&piles->a, &piles->b, 0);
		ptr = ptr->next;
	}
}

static void	get_commands(t_structs *piles)
{
	char		*str;
	t_commands	*commands;
	
	commands = ft_calloc(1, sizeof(t_commands));
	commands->data = get_next_line(0);
	commands->next = NULL;
	str = get_next_line(0);
	while (str != NULL)
	{
		add_commands_end(&commands, str);
		str = get_next_line(0);
	}
	do_op(commands, piles);
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
	get_commands(piles);
	if (sort_checker(&piles->a) == 0 && piles->b_count == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_all(piles, new_argv), 0);
}
