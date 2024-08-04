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

char	*ft_itoa(int nbr)
{
	int		i;
	int		tmp;
	char	*str;

	i = 0;
	if (nbr == 0)
		i = 1;
	tmp = nbr;
	while (tmp > 0)
	{
		i++;
		tmp /= 10;
	}
	i++;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}

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

void	ft_printf_mouve(t_dataStruct *data)
{
	fill_wall (data, 0, 2);
	data->str_mouv = ft_itoa (data->count);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 8, 15, 0xFF0000,
		"Movement : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 77, 15, 0xFF0000,
		data->str_mouv);
	free (data->str_mouv);
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
	ft_printf_mouve (data);
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
