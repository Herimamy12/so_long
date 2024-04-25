/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:26:43 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/25 13:36:42 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mouse(int action, void *param)
{
	t_wmap_mlx	*wmap_mlx;

	wmap_mlx = (t_wmap_mlx *)param;
	ft_printf ("%d\n", action);
	if (action == 65307)
	{	
		mlx_destroy_window (wmap_mlx->mlx_ptr, wmap_mlx->win_ptr);
		mlx_destroy_display (wmap_mlx->mlx_ptr);
		free(wmap_mlx->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	check_key(int key, void *param)
{
	t_wmap_mlx	*wmap_mlx;

	wmap_mlx = (t_wmap_mlx *)param;
	ft_printf ("%d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window (wmap_mlx->mlx_ptr, wmap_mlx->win_ptr);
		mlx_destroy_display (wmap_mlx->mlx_ptr);
		free(wmap_mlx->mlx_ptr);
		exit(0);
	}
	return (0);
}
