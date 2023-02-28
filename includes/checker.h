/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:00:36 by ztrottie          #+#    #+#             */
/*   Updated: 2023/02/28 16:44:43 by ztrottie         ###   ########.fr       */
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

#endif