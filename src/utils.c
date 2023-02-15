/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:09:02 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/15 11:18:48 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr)
	return (NULL);
}

int	*temp_array(int argc, char **argv)
{
	int	*tmp;
	
	tmp = (int *)ft_calloc(argc, sizeof(int));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < argc - 1)
		tmp[i] = ft_atoi(argv[i + 1]);
	return (tmp);
}