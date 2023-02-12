/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:07:28 by ztrottie          #+#    #+#             */
/*   Updated: 2022/12/14 14:15:07 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hexa_len(size_t nbr)
{
	size_t	i;
	size_t	nb;

	i = 0;
	if (nbr == 0)
		return (1);
	else
		nb = nbr;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}
