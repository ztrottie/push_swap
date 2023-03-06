/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:02:12 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/06 11:19:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include <unistd.h>

static void	*free_commands(t_commands *commands)
{
	t_commands	*ptr;
	t_commands	*tmp;

	ptr = commands;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ptr->data = ft_free(ptr->data);
		ptr = ft_free(ptr);
		ptr = tmp;
	}
	return (0);
}

static void	add_commands_end(t_commands **commands, char *str)
{
	t_commands	*ptr;
	t_commands	*new;

	if (*commands == NULL)
	{
		*commands = ft_calloc(1, sizeof(t_commands));
		(*commands)->data = str;
		(*commands)->next = NULL;
		return ;
	}
	ptr = *commands;
	while (ptr->next != NULL)
		ptr = ptr->next;
	new = ft_calloc(1, sizeof(t_commands));
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
		if (ft_strncmp(ptr->data, "rr", 2) == 0)
			reverse_rotation_operation(ptr->data, piles);
		else if (ft_strncmp(ptr->data, "r", 1) == 0)
			rotation_operation(ptr->data, piles);
		else if (ft_strncmp(ptr->data, "s", 1) == 0)
			swap_operation(ptr->data, piles);
		else if (ft_strncmp(ptr->data, "p", 1) == 0)
			push_operation(ptr->data, piles);
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
	free_commands(commands);
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
