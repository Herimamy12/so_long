/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:11:04 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/28 13:11:06 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_enemy0(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/en0.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_enemy1(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/en1.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_enemy2(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/en2.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_enemy3(t_dataStruct *p, int i, int j)
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

void	sprite_enemy(t_dataStruct *data, int i, int j)
{
	if ((data->d_state) == 0)
	{
		fill_enemy0 (data, i, j);
		(data->d_state) = 1;
		usleep (105555);
	}
	else if ((data->d_state) == 1)
	{
		fill_enemy1 (data, i, j);
		(data->d_state) = 2;
		usleep (105555);
	}
	else if ((data->d_state) == 2)
	{
		fill_enemy2 (data, i, j);
		(data->d_state) = 3;
		usleep (105555);
	}
	else if ((data->d_state) == 3)
	{
		fill_enemy3 (data, i, j);
		(data->d_state) = 0;
		usleep (105555);
	}
}
