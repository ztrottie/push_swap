/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:42 by ztrottie          #+#    #+#             */
/*   Updated: 2022/12/14 14:12:32 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned int nbr, char maj)
{
	unsigned int	nb;
	char			*hexa;
	int				i;

	i = 0;
	if (maj == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	nb = nbr;
	if (nb / ft_strlen(hexa) != 0)
		ft_putnbr_base((nb / ft_strlen(hexa)), maj);
	ft_putchar_fd(hexa[nb % ft_strlen(hexa)], 1);
	return (ft_hexa_len(nbr));
}
