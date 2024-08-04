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

void	check_the_second_path_error(char **map, int i, int y)
{
	int	ln;
	int	wdth;

	ln = count_length_map (map);
	wdth = count_width_map (map);
	if (i < 0 || i >= ln || y < 0 || y > wdth)
		return ;
	if (map[y][i] == '1' || map[y][i] == '8')
		return ;
	map[y][i] = '8';
	check_the_second_path_error (map, i - 1, y);
	check_the_second_path_error (map, i + 1, y);
	check_the_second_path_error (map, i, y - 1);
	check_the_second_path_error (map, i, y + 1);
}

int	count_enemy(t_dataStruct *data)
{
	int		i;
	int		j;
	int		ln;
	int		wdth;

	i = 0;
	ln = count_length_map (data->map);
	wdth = count_width_map (data->map);
	while (i < wdth)
	{
		j = 0;
		while (j < ln)
		{
			if (data->map[i][j] == 'd')
				return (42);
			j++;
		}
		i++;
	}
	return (0);
}
