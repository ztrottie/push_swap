/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:41:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/16 10:18:46 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**argv_conv(int *argc, char **argv)
{
	if (*argc == 2)
	{
		*argc = ft_word_count(argv[1], ' ') - 1;
		argv = ft_split(argv[1], ' ');
	}
	else
	{
		*argc = *argc - 1;
		argv = argv + 1;
	}
	return (argv);
}