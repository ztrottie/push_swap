/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:41:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/28 12:42:29 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

char	**argv_conv(int *argc, char **argv, t_structs *piles)
{
	char	**new_argv;

	if (*argc == 2)
	{
		*argc = ft_word_count(argv[1], ' ') - 1;
		new_argv = ft_split(argv[1], ' ');
		piles->temp = 1;
	}
	else
	{
		*argc = *argc - 1;
		new_argv = argv + 1;
	}
	return (new_argv);
}
