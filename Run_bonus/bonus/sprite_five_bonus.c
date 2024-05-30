/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_five_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:15:35 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/29 13:15:37 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_dataStruct *data)
{
	handle_keypress (65307, data);
	return (0);
}

void	ft_open_door(t_dataStruct *p, int ln, int wdth)
{
	int	i;
	int	j;

	i = 0;
	while (i < wdth)
	{
		j = 0;
		while (j < ln)
		{
			if (p->map[i][j] == 'E')
				fill_open_door (p, i, j);
			j++;
		}
		i++;
	}
}

int	check_door_close(int keycode, t_dataStruct *data, int i, int j)
{
	int	width;
	int	length;

	width = count_width_map (data->map);
	length = count_length_map (data->map);
	if (collector_error (data->map, length, width))
		return (0);
	else if (keycode == 119 && data->map[i - 1][j] != 'E')
		return (0);
	else if (keycode == 97 && data->map[i][j - 1] != 'E')
		return (0);
	else if (keycode == 115 && data->map[i + 1][j] != 'E')
		return (0);
	else if (keycode == 100 && data->map[i][j + 1] != 'E')
		return (0);
	return (42);
}

void	ft_mouve_management(int keycode, t_dataStruct *data, int i, int j)
{
	if (check_door_close (keycode, data, i, j))
		return ;
	else if (keycode == 119 && data->map[i - 1][j] != '1')
	{
		data->p_dstate = 'U';
		move_up (data, i, j);
	}
	else if (keycode == 97 && data->map[i][j - 1] != '1')
	{
		data->p_dstate = 'L';
		move_left (data, i, j);
	}
	else if (keycode == 115 && data->map[i + 1][j] != '1')
	{
		data->p_dstate = 'D';
		move_down (data, i, j);
	}
	else if (keycode == 100 && data->map[i][j + 1] != '1')
	{
		data->p_dstate = 'R';
		move_right (data, i, j);
	}
	else
		sprite_player (data, i, j);
}
