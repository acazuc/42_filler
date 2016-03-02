/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:55:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 11:02:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fill_piece_read(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	if (!(env->piece = malloc(sizeof(*env->piece) * (env->piece_height - 1))))
		error_quit("Failed to malloc map tab");
	while (i < env->piece_height)
	{
		if (!(line = get_next_line()))
			error_quit("Failed to read line");
		env->piece[i] = line;
		i++;
	}
}

void			read_piece(t_env *env)
{
	char	**tab;
	char	*line;

	if (!(line = get_next_line()))
		error_quit("Failde to read line");
	if (!ft_strstr(line, "Piece ") || line[ft_strlen(line) - 1] != ':')
		error_quit("Invalid line 1");
	if (!(tab = ft_strsplit(line, ' '))
			|| !tab[0] || !tab[1] || !tab[2] || tab[3])
		error_quit("Invalid line 2");
	if (ft_strlen(tab[2]) == 0 || !(tab[2] = ft_strsub(tab[2], 0
					, ft_strlen(tab[2]) - 1)))
		error_quit("Invalid second table size param");
	if (!ft_strisdigit(tab[1]) || !ft_strisdigit(tab[2]))
		error_quit("Invalid tab size");
	if (!valid_int(tab[1]) || !valid_int(tab[2]))
		error_quit("Invalid int");
	env->piece_width = ft_atoi(tab[2]);
	env->piece_height = ft_atoi(tab[1]);
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab);
	free(line);
	fill_piece_read(env);
}
