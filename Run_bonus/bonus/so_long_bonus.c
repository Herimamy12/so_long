/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:13:46 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:13:47 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	manage_all_state(t_dataStruct *data)
{
	if ((data->d_state) == 100)
		(data->d_state) = 0;
	else
		(data->d_state)++;
	if ((data->c_state) == 40)
		(data->c_state) = 0;
	else
		(data->c_state)++;
}

int	ft_sprite_animation(t_dataStruct *data)
{
	int		i;
	int		j;
	int		ln;
	int		wdth;

	i = 0;
	ln = count_length_map (data->map);
	wdth = count_width_map (data->map);
	manage_all_state (data);
	snprintf(data->mouv_text, sizeof(data->mouv_text), "texte : %d",
		data->count);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 15, 0xFF0000, data->mouv_text);
	while (i < wdth)
	{
		j = 0;
		while (j < ln)
		{
			if (data->map[i][j] == 'd')
				sprite_enemy (data, i, j);
			else if (data->map[i][j] == 'C')
				sprite_collector (data, i, j);
			j++;
		}
		i++;
	}
	usleep (4000);
	return (0);
}

void	so_long_bonus(t_dataStruct *data)
{
	int		ln;
	int		wdth;

	ln = count_length_map (data->map);
	wdth = count_width_map (data->map);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, ln * 35, wdth * 35, "M");
	if (!data->win_ptr)
		return ;
	fill_window (data, ln, wdth);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop_hook (data->mlx_ptr, ft_sprite_animation, data);
	mlx_loop(data->mlx_ptr);
}
