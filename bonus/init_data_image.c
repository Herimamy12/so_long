/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:04:25 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/29 11:04:26 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_data_player(t_dataStruct *data)
{
	data->plrr = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrR.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plrr1 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrR1.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plrr2 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrR2.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plrl = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrL.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plrl1 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrL1.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plrl2 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrL2.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plru = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrU.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plru1 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrU1.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plru2 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrU2.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plrd = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrD.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plrd1 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrD1.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->plrd2 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/plrD2.xpm", 
		&(data->img_wdth), &(data->img_lngth));
}

void	init_data_enemy_border_content(t_dataStruct *data)
{
	data->road = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/road.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->wall = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/wall.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->c = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/c.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->cldoor = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/clDoor.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->opdoor = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/opDoor.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->en0 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/en0.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->en1 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/en1.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->en2 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/en2.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->en3 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/en3.xpm", 
		&(data->img_wdth), &(data->img_lngth));
	data->en4 = mlx_xpm_file_to_image (data->mlx_ptr, "./ib/en4.xpm", 
		&(data->img_wdth), &(data->img_lngth));
}

void	init_data_image(t_dataStruct *data)
{
	init_data_player (data);
	init_data_enemy_border_content (data);
}
