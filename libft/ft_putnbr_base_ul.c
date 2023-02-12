/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:45:05 by ztrottie          #+#    #+#             */
/*   Updated: 2022/12/14 14:12:39 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_ul(unsigned long nbr)
{
	unsigned long	nb;
	char			*hexa;

	hexa = "0123456789abcdef";
	nb = nbr;
	if (nb / ft_strlen(hexa) != 0)
		ft_putnbr_base_ul((nb / 16));
	ft_putchar_fd(hexa[nb % 16], 1);
	return (ft_hexa_len(nbr));
}
