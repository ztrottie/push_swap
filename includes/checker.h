/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:00:36 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/13 14:39:51 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

typedef struct s_commands
{
	char				*data;
	struct s_commands	*next;
}	t_commands;

/*functions for the checker*/
char	*get_next_line(int fd);

/*commands selection functions*/
int	rotation_operation(char *command, t_structs *piles);
int	reverse_rotation_operation(char *command, t_structs *piles);
int	swap_operation(char *command, t_structs *piles);
int	push_operation(char *command, t_structs *piles);

#endif