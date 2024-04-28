/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herimamy <herimamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:26:43 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/27 21:32:05 by herimamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_player(t_wmap_mlx *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 50;
	ig_l = 50;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/prs0.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_wall(t_wmap_mlx *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 50;
	ig_l = 50;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/wall.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_road(t_wmap_mlx *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 50;
	ig_l = 50;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/road.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_window(t_wmap_mlx *p, int ln, int wdth)
{
	int	i;
	int	j;

	i = 0;
	while (i < wdth)
	{
		j = 0;
		while (j < ln)
		{
			if (p->map[i][j] == 'P')
				fill_player (p, i, j);
			else if (p->map[i][j] == '1')
				fill_wall (p, i, j);
			else if (p->map[i][j] == 'C')
				fill_collector (p, i, j);
			else if (p->map[i][j] == 'E')
				fill_exit (p, i, j);
			else if (p->map[i][j] == '0')
				fill_road (p, i, j);
			j++;
		}
		i++;
	}
}

// int close_window(int keycode, t_wmap_mlx *data)
// {
// 	if (keycode == 0)
// 		return (0);
// 	mlx_destroy_window (data->mlx_ptr, data->win_ptr);
// 	mlx_destroy_display (data->mlx_ptr);
// 	free_char_two_star (data->map);
// 	free(data->mlx_ptr);
// 	exit(0);
// }

void	so_long(t_wmap_mlx *p)
{
	int		ln;
	int		wdth;

	ln = count_length_map (p->map);
	wdth = count_width_map (p->map);
	p->mlx_ptr = mlx_init();
	if (!p->mlx_ptr)
		return ;
	p->win_ptr = mlx_new_window(p->mlx_ptr, ln * 50, wdth * 50, "so_long");
	if (!p->win_ptr)
		return ;
	fill_window (p, ln, wdth);
	mlx_key_hook (p->win_ptr, handle_keypress, p);
//	mlx_hook(p->win_ptr, 17, 0, close_window, p);
//	mlx_hook(p->win_ptr, 3, 1L << 1, handle_keypress, p);
//	mlx_loop_hook (p->mlx_ptr, handle_keypress, p);
	mlx_mouse_hook (p->win_ptr, check_mouse, p);
	mlx_loop(p->mlx_ptr);
}
