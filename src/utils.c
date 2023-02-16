/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:09:02 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/15 14:29:08 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
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
	
	tmp = (int *)ft_calloc(argc, sizeof(int));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < argc - 1)
		tmp[i] = ft_atoi(argv[i + 1]);
	return (tmp);
}

long int	ft_li_atoi(const char *str)
{
	long int	nb;
	int	sign;
	int	i;

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
