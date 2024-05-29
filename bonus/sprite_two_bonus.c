/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:12:39 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:12:40 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_player_right1(t_dataStruct *p, int i, int j)
{
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, 
		p->en0, j * 35, i * 35);
	ft_printf ("i = %d, j = %d, rigth 1111\n", i, j);
}

void	fill_player_right2(t_dataStruct *p, int i, int j)
{
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, 
		p->wall, j * 35, i * 35);
	ft_printf ("i = %d, j = %d, rigth 2222\n", i, j);
}

void	fill_player_left1(t_dataStruct *p, int i, int j)
{
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, 
		p->plrl1, j * 35, i * 35);
}

void	fill_player_left2(t_dataStruct *p, int i, int j)
{
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, 
		p->plrl2, j * 35, i * 35);
}

void	fill_player_up1(t_dataStruct *p, int i, int j)
{
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, 
		p->plru1, j * 35, i * 35);
}
