/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:09:02 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/22 11:44:16 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		trigger;

	i = 0;
	trigger = 1;
	count = 0;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || s[i] == 0) && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		else if (s[i] != c && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count + 1);
}

int	sort_checker(t_pile **a)
{
	t_pile	*ptr;

	ptr = *a;
	while (ptr->next != *a)
	{
		if (ptr->next->data < ptr->data)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	*temp_array(int argc, char **argv)
{
	int	*tmp;
	int	i;

	tmp = (int *)ft_calloc(argc + 1, sizeof(int));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < argc)
		tmp[i] = ft_atoi(argv[i]);
	return (tmp);
}

long int	ft_li_atoi(const char *str)
{
	long int	nb;
	int			sign;
	int			i;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sign);
}
