/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:06:22 by ztrottie          #+#    #+#             */
/*   Updated: 2022/12/14 14:12:26 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_len(long int n)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	if (n < 0)
	{
		nbr = n * -1;
		i++;
	}
	else if (n == 0)
		return (1);
	else
		nbr = n;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
