/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_for_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:12:59 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:13:02 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_dataStruct *data, int play_i, int play_j)
{
	if (data->map[play_i - 1][play_j] == 'E')
	{
		data->count++;
		fill_road (data, play_i, play_j);
		fill_player_up (data, play_i - 1, play_j);
		data->map[play_i][play_j] = '0';
		manage_to_leave (data);
	}
	else if (data->map[play_i][play_j] == 'E')
	{
		data->count++;
		fill_exit (data, play_i, play_j);
		fill_player_up (data, play_i - 1, play_j);
		data->map[play_i - 1][play_j] = 'P';
	}
	else
	{
		data->count++;
		fill_road (data, play_i, play_j);
		fill_player_up (data, play_i - 1, play_j);
		data->map[play_i][play_j] = '0';
		data->map[play_i - 1][play_j] = 'P';
	}
	ft_printf ("mouv = %d\n", data->count);
}

void	move_down(t_dataStruct *data, int play_i, int play_j)
{
	if (data->map[play_i + 1][play_j] == 'E')
	{
		data->count++;
		fill_road (data, play_i, play_j);
		fill_player_down (data, play_i + 1, play_j);
		data->map[play_i][play_j] = '0';
		manage_to_leave (data);
	}
	else if (data->map[play_i][play_j] == 'E')
	{
		data->count++;
		fill_exit (data, play_i, play_j);
		fill_player_down (data, play_i + 1, play_j);
		data->map[play_i + 1][play_j] = 'P';
	}
	else
	{
		data->count++;
		fill_road (data, play_i, play_j);
		fill_player_down (data, play_i + 1, play_j);
		data->map[play_i][play_j] = '0';
		data->map[play_i + 1][play_j] = 'P';
	}
	ft_printf ("mouv = %d\n", data->count);
}

void	move_left(t_dataStruct *data, int play_i, int play_j)
{
	if (data->map[play_i][play_j - 1] == 'E')
	{
		data->count++;
		fill_road (data, play_i, play_j);
		fill_player_left (data, play_i, play_j - 1);
		data->map[play_i][play_j] = '0';
		manage_to_leave (data);
	}
	else if (data->map[play_i][play_j] == 'E')
	{
		data->count++;
		fill_exit (data, play_i, play_j);
		fill_player_left (data, play_i, play_j - 1);
		data->map[play_i][play_j - 1] = 'P';
	}
	else
	{
		data->count++;
		fill_road (data, play_i, play_j);
		fill_player_left (data, play_i, play_j - 1);
		data->map[play_i][play_j] = '0';
		data->map[play_i][play_j - 1] = 'P';
	}
	ft_printf ("mouv = %d\n", data->count);
}

void	move_right(t_dataStruct *data, int play_i, int play_j)
{
	if (data->map[play_i][play_j + 1] == 'E')
	{
		data->count++;
		fill_road (data, play_i, play_j);
		fill_player_right (data, play_i, play_j + 1);
		data->map[play_i][play_j] = '0';
		manage_to_leave (data);
	}
	else if (data->map[play_i][play_j] == 'E')
	{
		data->count++;
		fill_exit (data, play_i, play_j);
		fill_player_right (data, play_i, play_j + 1);
		data->map[play_i][play_j + 1] = 'P';
	}
	else
	{
		data->count++;
		fill_road (data, play_i, play_j);
		fill_player_right (data, play_i, play_j + 1);
		data->map[play_i][play_j] = '0';
		data->map[play_i][play_j + 1] = 'P';
	}
	ft_printf ("mouv = %d\n", data->count);
}

int	handle_keypress(int keycode, t_dataStruct *data)
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
	if (collector_error (data->map, length, width))
		ft_open_door (data, length, width);
	ft_mouve_management (keycode, data, play_i, play_j);
	return (0);
}
