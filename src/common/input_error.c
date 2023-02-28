/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:38:36 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/28 12:42:43 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

static int	nb_checker(int argc, char **argv)
{
	int	i;
	int	len;

	i = -1;
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

	i = -1;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
	}
	return (0);
}

static int	nb_double(int argc, char **argv)
{
	int	*tmp;
	int	i;
	int	i2;

	tmp = temp_array(argc, argv);
	if (tmp == NULL)
		return (1);
	i = 0;
	while (i < argc)
	{
		i2 = i + 1;
		while (i2 < argc)
		{
			if (tmp[i] == tmp [i2])
				return (free(tmp), 1);
			i2++;
		}
		i++;
	}
	return (free(tmp), 0);
}

int	input_error(int argc, char **argv)
{
	if (argv_checker(argc, argv))
		return (1);
	if (nb_checker(argc, argv))
		return (1);
	if (nb_double(argc, argv))
		return (1);
	return (0);
}
