/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:00:36 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/06 11:18:10 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"
# include <stdio.h>

typedef struct s_commands
{
	char				*data;
	struct s_commands	*next;
}	t_commands;

/*functions for the checker*/
char	*get_next_line(int fd);

/*commands selection functions*/
void	rotation_operation(char *command, t_structs *piles);
void	reverse_rotation_operation(char *command, t_structs *piles);
void	swap_operation(char *command, t_structs *piles);
void	push_operation(char *command, t_structs *piles);

#endif