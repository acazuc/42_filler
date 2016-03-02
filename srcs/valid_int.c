/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:22:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 10:16:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		valid_int(char *value)
{
	long	atoled;

	if (value[0] == '-')
	{
		if (ft_strlen(value) > 11)
			return (0);
	}
	else if (ft_strlen(value) > 10)
		return (0);
	if ((atoled = ft_atol(value)) > INT_MAX || atoled < INT_MIN)
		return (0);
	return (1);
}
