/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_for_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:56:50 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/29 12:56:51 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_error(char **map, int length, int width)
{
	int	i;
	int	j;
	int	count_enemy;

	i = 0;
	count_enemy = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (map[i][j] == 'd')
				count_enemy++;
			j++;
		}
		i++;
	}
	if (count_enemy > 1)
		return (42);
	return (0);
}
