/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:02:12 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/28 16:08:37 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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
		else if (ft_strncmp(ptr->data, "sa", 2) == 0)
			sa(&piles->a, piles->a_count, 0);
		ptr = ptr->next;
	}
}

static void	get_commands(t_structs *piles)
{
	char		*str;
	int			fd;
	t_commands	*ptr;
	t_commands	*commands;
	
	fd = open("text.txt", O_RDONLY);
	commands = (t_commands *)ft_calloc(1, sizeof(t_commands));
	commands->data = get_next_line(fd);
	commands->next = NULL;
	str = get_next_line(fd);
	ft_printf("%s\n", str);
	while (str != NULL)
	{
		add_commands_end(&commands, str);
		str = get_next_line(fd);
	}
	ptr = commands;
	while (ptr != NULL)
	{
		ft_printf("%s\n", ptr->data);
		ptr = ptr->next;
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
