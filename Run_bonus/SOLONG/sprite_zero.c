/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:39:16 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 10:39:19 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_open_door(t_wmap_mlx *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 50;
	ig_l = 50;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/opDoor.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

int	check_door_close(int keycode, t_wmap_mlx *data, int i, int j)
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

void	ft_mouve_management(int keycode, t_wmap_mlx *data, int i, int j)
{
	if (keycode == 65307)
		exit_window (data);
	if (check_door_close (keycode, data, i, j))
		return ;
	else if (keycode == 119 && data->map[i - 1][j] != '1')
		move_up (data, i, j);
	else if (keycode == 97 && data->map[i][j - 1] != '1')
		move_left (data, i, j);
	else if (keycode == 115 && data->map[i + 1][j] != '1')
		move_down (data, i, j);
	else if (keycode == 100 && data->map[i][j + 1] != '1')
		move_right (data, i, j);
}
