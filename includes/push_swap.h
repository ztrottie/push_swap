/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:32:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/15 18:59:29 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "../libft/libft.h"
# include <stdio.h>

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
void		sa(t_pile **a, int count, int print);
void		sb(t_pile **b, int count, int print);
void		ss(t_structs **piles);

/*Rotation functions*/
void		ra(t_pile **a, int print);
void		rb(t_pile **b, int print);
void		rr(t_pile **a, t_pile **b);

/*Reverse rotation functions*/
void		rra(t_pile **a, int print);
void		rrb(t_pile **b, int print);
void		rrr(t_pile **a, t_pile **b);

/*Push functions*/
void		pa(t_structs **piles);
void		pb(t_structs **piles);

/*Error handling functions*/
int			input_error(int argc, char **argv);

/*Initialization of all the structs and indexation of numbers*/
int			init_push_swap(int argc, char **argv, t_structs **piles);

/*type of algos*/
void	xs_algo(t_structs **piles);
/*Pile functions*/
int			pile_add_end(int data, t_pile **pile);
void		free_pile(t_pile *pile);
void		*free_all(t_structs *piles);

/*Other functions*/
long int	ft_li_atoi(const char *str);
int			*temp_array(int argc, char **argv);
void		*ft_free(void *ptr);
int			sort_checker(t_pile **a);

#endif