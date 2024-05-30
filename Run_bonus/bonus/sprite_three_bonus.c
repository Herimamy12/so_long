/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_three_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:12:48 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:12:49 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_player_up2(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/plrU2.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_player_down1(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/plrD1.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	fill_player_down2(t_dataStruct *p, int i, int j)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	ig_w = 35;
	ig_l = 35;
	ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./ib/plrD2.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 35, i * 35);
	mlx_destroy_image (p->mlx_ptr, ig_p);
}

void	exit_window(t_dataStruct *data)
{
	mlx_destroy_window (data->mlx_ptr, data->win_ptr);
	mlx_destroy_display (data->mlx_ptr);
	free_char_two_star (data->map);
	free(data->mlx_ptr);
	exit(0);
}

void	manage_to_leave(t_dataStruct *data)
{
	int	width;
	int	length;

	width = count_width_map (data->map);
	length = count_length_map (data->map);
	if (collector_error (data->map, length, width))
	{
		ft_printf ("mouv = %d\n", data->count);
		ft_printf ("You Win\n");
		exit_window (data);
	}
}
