/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:32:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/01 23:04:03 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

/*type of algos*/
void		xs_algo(t_structs *piles);
void		ultimate_sort(t_structs *piles);

/*Sort commands*/
void		three_sort_a(t_structs *piles);
void		three_sort_b(t_structs *piles);
void		two_sort_a(t_structs *piles);
void		two_sort_b(t_structs *piles);

/*Block Manipulation*/
void		block_sep(t_structs *piles, int block);
int			block_alloc(t_structs *piles);
void		block_init(t_structs *piles);
void		block_count(t_structs *piles);

#endif