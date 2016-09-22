/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 15:29:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/04 11:10:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"

char	*get_next_line(void);
void	error_quit(char *error);
void	read_table(t_env *env);
void	read_piece(t_env *env);
int		valid_int(char *value);
void	print_place(t_env *env);
void	read_player_char(t_env *env);

#endif
