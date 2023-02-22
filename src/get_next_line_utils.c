/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:11:13 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/22 13:34:52 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*ptr;
	size_t		len1;
	size_t		len2;
	size_t		i;
	size_t		j;

	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	ptr = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (++i < len1)
		ptr[i] = s1[i];
	j = -1;
	while (++j < len2 + 1)
		ptr[j + i] = s2[j];
	return (s1 = ft_free(s1), ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_bzero(void *p, size_t size)
{
	while (size--)
		((char *)p)[size] = 0;
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
