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

void	manage_to_leave(t_wmap_mlx *data)
{
	int	width;
	int	length;

	width = count_width_map (data->map);
	length = count_length_map (data->map);
	if (collector_error (data->map, length, width))
	{
		ft_printf ("mouv = %d\n", data->count);
		exit_window (data);
	}
}

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
	mlx_hook(p->win_ptr, 2, 1L << 0, handle_keypress, p);
	mlx_hook(p->win_ptr, 17, 0, close_window, p);
	mlx_loop(p->mlx_ptr);
}
