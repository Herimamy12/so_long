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

int	close_window(t_wmap_mlx *data)
{
	handle_keypress (65307, data);
	return (0);
}
