/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_next_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herimamy <herimamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:27:02 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/27 20:58:57 by herimamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_collector(t_wmap_mlx *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 50;
	ig_l = 50;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/C.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_exit(t_wmap_mlx *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 50;
	ig_l = 50;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/E.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	exit_window(t_wmap_mlx *data)
{
	mlx_destroy_window (data->mlx_ptr, data->win_ptr);
	mlx_destroy_display (data->mlx_ptr);
	free_char_two_star (data->map);
	free(data->mlx_ptr);
	exit(0);
}

int	check_mouse(int action, void *param)
{
	t_wmap_mlx	*wmap_mlx;

	wmap_mlx = (t_wmap_mlx *)param;
	ft_printf ("%d\n", action);
	if (action == 65307)
	{
		mlx_destroy_window (wmap_mlx->mlx_ptr, wmap_mlx->win_ptr);
		mlx_destroy_display (wmap_mlx->mlx_ptr);
		free_char_two_star (wmap_mlx->map);
		free(wmap_mlx->mlx_ptr);
		exit(0);
	}
	return (0);
}

void	manage_to_leave(t_wmap_mlx *data)
{
	int	width;
	int	length;

	width = count_width_map (data->map);
	length = count_length_map (data->map);
	if (collector_error (data->map, length, width))
		exit_window (data);
}
