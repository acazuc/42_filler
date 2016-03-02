/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 15:30:48 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 11:34:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_env	env;

	read_player_char(&env);
	while (42)
	{
		read_table(&env);
		read_piece(&env);
		print_place(&env);
	}
	return (0);
}
