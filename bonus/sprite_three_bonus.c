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
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, 
		p->plru2, j * 35, i * 35);
}

void	fill_player_down1(t_dataStruct *p, int i, int j)
{
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, 
		p->plrd1, j * 35, i * 35);
}

void	fill_player_down2(t_dataStruct *p, int i, int j)
{
	mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, 
		p->plrd2, j * 35, i * 35);
}
