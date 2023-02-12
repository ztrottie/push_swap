/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:40:29 by ztrottie          #+#    #+#             */
/*   Updated: 2022/11/17 16:36:00 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return (0);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
		{
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	return (dst);
}
