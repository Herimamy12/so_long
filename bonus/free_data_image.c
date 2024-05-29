/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:06:03 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/29 11:06:04 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_data_player(t_dataStruct *data)
{
	mlx_destroy_image (data->mlx_ptr, data->plrr);
	mlx_destroy_image (data->mlx_ptr, data->plrr1);
	mlx_destroy_image (data->mlx_ptr, data->plrr2);
	mlx_destroy_image (data->mlx_ptr, data->plrl);
	mlx_destroy_image (data->mlx_ptr, data->plrl1);
	mlx_destroy_image (data->mlx_ptr, data->plrl2);
	mlx_destroy_image (data->mlx_ptr, data->plru);
	mlx_destroy_image (data->mlx_ptr, data->plru1);
	mlx_destroy_image (data->mlx_ptr, data->plru2);
	mlx_destroy_image (data->mlx_ptr, data->plrd);
	mlx_destroy_image (data->mlx_ptr, data->plrd1);
	mlx_destroy_image (data->mlx_ptr, data->plrd2);
}

void	free_data_enemy_border_content(t_dataStruct *data)
{
	mlx_destroy_image (data->mlx_ptr, data->road);
	mlx_destroy_image (data->mlx_ptr, data->wall);
	mlx_destroy_image (data->mlx_ptr, data->c);
	mlx_destroy_image (data->mlx_ptr, data->cldoor);
	mlx_destroy_image (data->mlx_ptr, data->opdoor);
	mlx_destroy_image (data->mlx_ptr, data->en0);
	mlx_destroy_image (data->mlx_ptr, data->en1);
	mlx_destroy_image (data->mlx_ptr, data->en2);
	mlx_destroy_image (data->mlx_ptr, data->en3);
	mlx_destroy_image (data->mlx_ptr, data->en4);
}

void	free_data_image(t_dataStruct *data)
{
	free_data_player (data);
	free_data_enemy_border_content (data);
}
