/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:20:05 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 11:38:33 by acazuc           ###   ########.fr       */
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
	int		overlap;
	int		i;
	int		j;

	overlap = 0;
	i = 0;
	while (i < env->piece_height)
	{
		j = 0;
		while (j < env->piece_width)
		{
			if (env->piece[i][j] == '*')
			{
				if (env->map[y + i][x + j] == env->player_char)
					overlap++;
				else if (env->map[y + i][x + j] != '.')
					return (0);
			}
			j++;
		}
		i++;
	}
	if (overlap == 1)
		return (1);
	return (0);
}

int			print_place_border(t_env *env, int i)
{
	int		x;

	x = i - 1;
	while (++x < env->map_width - env->piece_width - i)
		if (fit(env, x, i))
		{
			print(i, x);
			return (1);
		}
	x = i - 1;
	while (++x < env->map_height - env->piece_height - i)
		if (fit(env, env->map_width - env->piece_width - i - 1, x))
		{
			print(x, env->map_width - env->piece_width - i - 1);
			return (1);
		}
	return (0);
}

int			print_place_border_2(t_env *env, int i)
{
	int		x;

	x = env->map_width - env->piece_width - i;
	while (--x >= i)
		if (fit(env, x, env->map_height - env->piece_height - i - 1))
		{
			print(env->map_height - env->piece_height - i - 1, x);
			return (1);
		}
	x = env->map_height - env->piece_height - i;
	while (--x >= i)
		if (fit(env, i, x))
		{
			print(x, i);
			return (1);
		}
	return (0);
}

void			print_place(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->map_width + env->map_height)
	{
		if (print_place_border(env, i))
			return ;
		if (print_place_border_2(env, i))
			return ;
		i++;
	}
	print(0, 0);
}
