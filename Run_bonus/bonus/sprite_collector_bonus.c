/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collector_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:33:50 by nherimam          #+#    #+#             */
/*   Updated: 2024/06/01 12:33:51 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_collector0(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/C.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_collector1(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/C1.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_collector2(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/C2.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_collector3(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/C3.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	sprite_collector(t_dataStruct *data, int i, int j)
{
	if ((data->d_state) < 10)
		fill_collector0 (data, i, j);
	else if ((data->d_state) < 20)
		fill_collector1 (data, i, j);
	else if ((data->d_state) < 30)
		fill_collector2 (data, i, j);
	else if ((data->d_state) < 40)
		fill_collector3 (data, i, j);
}
