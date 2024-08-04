/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_enemy_two_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:16:56 by nherimam          #+#    #+#             */
/*   Updated: 2024/06/04 10:17:02 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_path_in_line(t_dataStruct *data, int i, int j)
{
	(data->enemy_i) = i;
	if (data->map[data->enemy_i][data->enemy_j + 1] == '0')
	{
		(data->enemy_j)++;
		fill_road (data, i, j);
		sprite_enemy (data, data->enemy_i, data->enemy_j);
		data->map[i][j] = '0';
		data->map[data->enemy_i][data->enemy_j] = 'd';
	}
	else if (data->map[data->enemy_i][data->enemy_j - 1] == '0')
	{
		(data->enemy_j)--;
		fill_road (data, i, j);
		sprite_enemy (data, data->enemy_i, data->enemy_j);
		data->map[i][j] = '0';
		data->map[data->enemy_i][data->enemy_j] = 'd';
	}
}

void	check_path_in_col(t_dataStruct *data, int i, int j)
{
	(data->enemy_j) = j;
	if (data->map[data->enemy_i + 1][data->enemy_j] == '0')
	{
		(data->enemy_i)++;
		fill_road (data, i, j);
		sprite_enemy (data, data->enemy_i, data->enemy_j);
		data->map[i][j] = '0';
		data->map[data->enemy_i][data->enemy_j] = 'd';
	}
	else if (data->map[data->enemy_i - 1][data->enemy_j] == '0')
	{
		(data->enemy_i)--;
		fill_road (data, i, j);
		sprite_enemy (data, data->enemy_i, data->enemy_j);
		data->map[i][j] = '0';
		data->map[data->enemy_i][data->enemy_j] = 'd';
	}
}

void	check_other_path(t_dataStruct *data, int i, int j)
{
	if (i != (data->enemy_i))
		check_path_in_line (data, i, j);
	else
		check_path_in_col (data, i, j);
}
