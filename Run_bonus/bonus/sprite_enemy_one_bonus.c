/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_enemy_one_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:01:44 by nherimam          #+#    #+#             */
/*   Updated: 2024/06/01 12:01:46 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_enemy4(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/en4.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	find_i_position_enemy(t_dataStruct *data)
{
	int	width;
	int	length;

	width = count_width_map (data->map);
	length = count_length_map (data->map);
	data->player_i = find_pos_y (data->map, length, width, 'P');
	data->enemy_i = find_pos_y (data->map, length, width, 'd');
	if ((data->player_i) > (data->enemy_i))
		(data->enemy_i)++;
	else if ((data->player_i) < (data->enemy_i))
		(data->enemy_i)--;
}

void	find_j_position_enemy(t_dataStruct *data)
{
	int	width;
	int	length;

	width = count_width_map (data->map);
	length = count_length_map (data->map);
	data->player_j = find_pos_i (data->map, length, width, 'P');
	data->enemy_j = find_pos_i (data->map, length, width, 'd');
	if ((data->player_j) > (data->enemy_j))
		(data->enemy_j)++;
	else if ((data->player_j) < (data->enemy_j))
		(data->enemy_j)--;
}

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

void	real_move(t_dataStruct *data, int i, int j)
{
	if (data->map[data->enemy_i][data->enemy_j] == 'P')
	{
		fill_road (data, i, j);
		sprite_enemy (data, data->enemy_i, data->enemy_j);
		ft_printf ("You Lose\n");
		handle_keypress (65307, data);
	}
	else if (data->map[data->enemy_i][data->enemy_j] != '0')
		check_other_path (data, i, j);
	else
	{
		fill_road (data, i, j);
		sprite_enemy (data, data->enemy_i, data->enemy_j);
		data->map[i][j] = '0';
		data->map[data->enemy_i][data->enemy_j] = 'd';
	}
}

void	move_the_enemy(t_dataStruct *data)
{
	int	i;
	int	j;
	int	width;
	int	length;

	width = count_width_map (data->map);
	length = count_length_map (data->map);
	i = find_pos_y (data->map, length, width, 'd');
	j = find_pos_i (data->map, length, width, 'd');
	data->enemy_j = j;
	find_i_position_enemy (data);
	if (i == (data->enemy_i))
		find_j_position_enemy (data);
	real_move (data, i, j);
}
