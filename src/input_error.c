/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:38:36 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/12 15:40:32 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	nb_checker(int argc, char **argv)
{
	int	i;
	int len;

	i = 0;
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len > 11)
			return (1);
		if (len == 11 && ft_li_atoi(argv[i]) < INT_MIN)
			return (1);
		if (len == 10 && ft_li_atoi(argv[i]) > INT_MAX)
			return (1);
	}
	return (0);
}

static int	argv_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc - 1)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while(argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
	}
	return (0);
}

int	input_error(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	if (argv_checker(argc, argv))
		return (1);
	if (nb_checker(argc, argv))
		return (1);
	return (0);
}