/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_playe_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:30:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 15:58:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_player_char(t_env *env)
{
	char	**split;
	char	*line;

	if (!(line = get_next_line()))
		error_quit("Failed to read line");
	if (!(split = ft_strsplit(line, ' ')))
		error_quit("Failed to split line");
	if (!split[0] || !split[1] || !split[2]
			|| !split[3] || !split[4] || split[5])
		error_quit("Bad split line");
	if (!ft_strcmp(split[2], "p1"))
		env->player_char = 'O';
	else if (!ft_strcmp(split[2], "p2"))
		env->player_char = 'X';
	else
		error_quit("Invalid player char line");
}
