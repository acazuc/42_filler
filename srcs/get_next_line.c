/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 15:57:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 10:34:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*get_next_line(void)
{
	char	*line;
	char	*buff;
	int		rd;

	if (!(buff = ft_memalloc(2)))
		error_quit("Failed to read next line");
	if (!(line = ft_memalloc(2)))
		error_quit("Failed to read next line");
	while ((rd = read(0, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
		{
			free(buff);
			return (line);
		}
		if (!(line = ft_strjoin_free1(line, buff)))
			error_quit("Failed to read next line");
	}
	if (rd == -1)
		error_quit("Failed to read next line");
	free(buff);
	return (line);
}
