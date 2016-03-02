/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 16:08:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 11:41:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fill_table_read(t_env *env)
{
	char	**tmp;
	char	*line;
	int		i;

	i = 0;
	if (!(env->map = malloc(sizeof(*env->map) * (env->map_height + 1))))
		error_quit("Failed to malloc map tab");
	free(get_next_line());
	while (i < env->map_height)
	{
		if (!(line = get_next_line()))
			error_quit("Failed to read line");
		if (!(tmp = ft_strsplit(line, ' ')))
			error_quit(": Failed to split line");
		free(line);
		if (!tmp[0] || !tmp[1] || tmp[2])
			error_quit("Failed to split nice line");
		free(tmp[0]);
		env->map[i] = tmp[1];
		free(tmp[2]);
		i++;
	}
	env->map[i] = NULL;
}

void			read_table(t_env *env)
{
	char	**tab;
	char	*line;

	if (!(line = get_next_line()))
		error_quit("Failed to read line");
	if (!ft_strstr(line, "Plateau ") || line[ft_strlen(line) - 1] != ':')
		error_quit("Invalid line plateau");
	if (!(tab = ft_strsplit(line, ' '))
			|| !tab[0] || !tab[1] || !tab[2] || tab[3])
		error_quit("Failed to malloc split tab");
	if (ft_strlen(tab[2]) == 0 || !(tab[2] = ft_strsub(tab[2]
					, 0, ft_strlen(tab[2]) - 1)))
		error_quit("Invalid second table size param");
	if (!ft_strisdigit(tab[1]) || !ft_strisdigit(tab[2]))
		error_quit("Failed to read table size");
	if (!valid_int(tab[1]) || !valid_int(tab[2]))
		error_quit("Invalid int value");
	env->map_width = ft_atoi(tab[2]);
	env->map_height = ft_atoi(tab[1]);
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab);
	free(line);
	fill_table_read(env);
}
