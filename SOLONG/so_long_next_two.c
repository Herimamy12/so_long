/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_next_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:27:14 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/26 08:39:28 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_wmap_mlx *data, int play_i, int play_j)
{
	if (data->map[play_i - 1][play_j] == 'E')
	{
		fill_road (data, play_i, play_j);
		fill_player (data, play_i - 1, play_j);
		data->map[play_i][play_j] = '0';
		manage_to_leave (data);
	}
	else if (data->map[play_i][play_j] == 'E')
	{
		fill_exit (data, play_i, play_j);
		fill_player (data, play_i - 1, play_j);
		data->map[play_i - 1][play_j] = 'P';
	}
	else
	{
		fill_road (data, play_i, play_j);
		fill_player (data, play_i - 1, play_j);
		data->map[play_i][play_j] = '0';
		data->map[play_i - 1][play_j] = 'P';
	}
}

void	move_down(t_wmap_mlx *data, int play_i, int play_j)
{
	if (data->map[play_i + 1][play_j] == 'E')
	{
		fill_road (data, play_i, play_j);
		fill_player (data, play_i + 1, play_j);
		data->map[play_i][play_j] = '0';
		manage_to_leave (data);
	}
	else if (data->map[play_i][play_j] == 'E')
	{
		fill_exit (data, play_i, play_j);
		fill_player (data, play_i + 1, play_j);
		data->map[play_i + 1][play_j] = 'P';
	}
	else
	{
		fill_road (data, play_i, play_j);
		fill_player (data, play_i + 1, play_j);
		data->map[play_i][play_j] = '0';
		data->map[play_i + 1][play_j] = 'P';
	}
}

void	move_left(t_wmap_mlx *data, int play_i, int play_j)
{
	if (data->map[play_i][play_j - 1] == 'E')
	{
		fill_road (data, play_i, play_j);
		fill_player (data, play_i, play_j - 1);
		data->map[play_i][play_j] = '0';
		manage_to_leave (data);
	}
	else if (data->map[play_i][play_j] == 'E')
	{
		fill_exit (data, play_i, play_j);
		fill_player (data, play_i, play_j - 1);
		data->map[play_i][play_j - 1] = 'P';
	}
	else
	{
		fill_road (data, play_i, play_j);
		fill_player (data, play_i, play_j - 1);
		data->map[play_i][play_j] = '0';
		data->map[play_i][play_j - 1] = 'P';
	}
}

void	move_right(t_wmap_mlx *data, int play_i, int play_j)
{
	if (data->map[play_i][play_j + 1] == 'E')
	{
		fill_road (data, play_i, play_j);
		fill_player (data, play_i, play_j + 1);
		data->map[play_i][play_j] = '0';
		manage_to_leave (data);
	}
	else if (data->map[play_i][play_j] == 'E')
	{
		fill_exit (data, play_i, play_j);
		fill_player (data, play_i, play_j + 1);
		data->map[play_i][play_j + 1] = 'P';
	}
	else
	{
		fill_road (data, play_i, play_j);
		fill_player (data, play_i, play_j + 1);
		data->map[play_i][play_j] = '0';
		data->map[play_i][play_j + 1] = 'P';
	}
}

int	handle_keypress(int keycode, t_wmap_mlx *data)
{
	int	width;
	int	play_i;
	int	play_j;
	int	length;

	width = count_width_map (data->map);
	length = count_length_map (data->map);
	play_i = find_pos_y (data->map, length, width, 'P');
	play_j = find_pos_i (data->map, length, width, 'P');
	if (play_i == 0 && play_j == 0)
	{
		play_i = find_pos_y (data->map, length, width, 'E');
		play_j = find_pos_i (data->map, length, width, 'E');
	}
	if (keycode == 65307)
		exit_window (data);
	else if (keycode == 122 && data->map[play_i - 1][play_j] != '1')
		move_up (data, play_i, play_j);
	else if (keycode == 113 && data->map[play_i][play_j - 1] != '1')
		move_left (data, play_i, play_j);
	else if (keycode == 115 && data->map[play_i + 1][play_j] != '1')
		move_down (data, play_i, play_j);
	else if (keycode == 100 && data->map[play_i][play_j + 1] != '1')
		move_right (data, play_i, play_j);
	return (0);
}
