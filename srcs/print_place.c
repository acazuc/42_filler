/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:20:05 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 11:39:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		print(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

static int		fit(t_env *env, int x, int y)
{
	int		overlap_nb;
	int		i;
	int		j;

	overlap_nb = 0;
	i = 0;
	while (i < env->piece_height)
	{
		j = 0;
		while (j < env->piece_width)
		{
			if (env->piece[i][j] == '*'
					&& env->map[y + i][x + j] == env->player_char)
				overlap_nb++;
			j++;
		}
		i++;
	}
	return (overlap_nb == 1);
}

void			print_place(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->map_height - env->piece_height)
	{
		x = 0;
		while (x < env->map_width - env->piece_width)
		{
			if (fit(env, x, y))
			{
				if (env->player_char == 'O')
					env->player_char = 'o';
				else if (env->player_char == 'X')
					env->player_char = 'x';
				print(y, x);
				return ;
			}
			x++;
		}
		y++;
	}
	print(0, 0);
}
