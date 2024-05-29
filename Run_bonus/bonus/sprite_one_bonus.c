/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_one_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:12:31 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:12:32 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_player_right(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/plrR.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_player_left(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/plrL.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_player_up(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/plrU.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_player_down(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/plrD.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_open_door(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/opDoor.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}
