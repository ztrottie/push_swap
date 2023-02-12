/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:32:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/12 16:12:56 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "../libft/libft.h"

/*double linked list of my values*/
typedef struct s_pile
{
	int				data;
	struct s_pile*	prev;
	struct s_pile*	next;
}	t_pile;

/*structure of everything needed*/
typedef struct s_structs
{
	int	total_count;
	int	a_count;
	int	b_count;
	t_pile *a;
	t_pile *b;
}	t_structs;


/*Swap functions*/
void	sa(t_pile **a, int print);
void	sb(t_pile **b, int print);
void	ss(t_pile **a, t_pile **b);

/*Rotation functions*/
void	ra(t_pile **a, int print);
void	rb(t_pile **b, int print);
void	rr(t_pile **a, t_pile **b);

/*Reverse rotation functions*/
void	rra(t_pile **a, int print);
void	rrb(t_pile **b, int print);
void	rrr(t_pile **a, t_pile **b);

/*Push functions*/
t_structs	*pa(t_structs *piles);
t_structs	*pb(t_structs *piles);

/*Error handling functions*/
int			input_error(int argc, char **argv);

/*Other functions*/
long int	ft_li_atoi(const char *str);

#endif