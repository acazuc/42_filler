/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:36:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/04 11:10:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct		s_env
{
	char			**piece;
	int				piece_width;
	int				piece_height;
	char			**map;
	int				map_width;
	int				map_height;
	char			player_char;
}					t_env;

#endif
