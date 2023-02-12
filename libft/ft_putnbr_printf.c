/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:55:43 by ztrottie          #+#    #+#             */
/*   Updated: 2022/12/14 14:12:18 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_printf(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar_fd('-', 1);
	}
	else
		nbr = n;
	if (nbr / 10 != 0)
		ft_putnbr_fd(nbr / 10, 1);
	ft_putchar_fd(nbr % 10 + '0', 1);
	return (ft_putnbr_len(n));
}
