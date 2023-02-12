/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:01:01 by ztrottie          #+#    #+#             */
/*   Updated: 2022/11/17 14:19:57 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_size(long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_is_negative(char *ptr, long int nb, int size)
{
	nb *= -1;
	ptr[0] = '-';
	while (--size >= 1)
	{
		ptr[size] = nb % 10 + '0';
		nb /= 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int				size;
	long int		nb;
	char			*ptr;

	nb = n;
	size = ft_check_size(nb);
	ptr = (char *)ft_calloc(size + 1, sizeof(char));
	if (!ptr)
		return (0);
	if (n < 0)
		ptr = ft_is_negative(ptr, nb, size);
	else if (n == 0)
		ptr[0] = '0';
	else
	{
		while (--size >= 0)
		{
			ptr[size] = nb % 10 + '0';
			nb /= 10;
		}
	}
	return (ptr);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(1000034));
}*/