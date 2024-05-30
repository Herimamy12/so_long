/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:47:45 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/30 09:47:58 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sprite_player_right(t_dataStruct *data, int i, int j)
{
	if ((data->p_state) == 0)
	{
		fill_player_right (data, i, j);
		(data->p_state) = 1;
	}
	else if ((data->p_state) == 1)
	{
		fill_player_right2 (data, i, j);
		(data->p_state) = 2;
	}
	else if ((data->p_state) == 2)
	{
		fill_player_right1 (data, i, j);
		(data->p_state) = 0;
	}
}

void	sprite_player_left(t_dataStruct *data, int i, int j)
{
	if ((data->p_state) == 0)
	{
		fill_player_left (data, i, j);
		(data->p_state) = 1;
	}
	else if ((data->p_state) == 1)
	{
		fill_player_left2 (data, i, j);
		(data->p_state) = 2;
	}
	else if ((data->p_state) == 2)
	{
		fill_player_left1 (data, i, j);
		(data->p_state) = 0;
	}
}

void	sprite_player_up(t_dataStruct *data, int i, int j)
{
	if ((data->p_state) == 0)
	{
		fill_player_up (data, i, j);
		(data->p_state) = 1;
	}
	else if ((data->p_state) == 1)
	{
		fill_player_up2 (data, i, j);
		(data->p_state) = 2;
	}
	else if ((data->p_state) == 2)
	{
		fill_player_up1 (data, i, j);
		(data->p_state) = 0;
	}
}

void	sprite_player_down(t_dataStruct *data, int i, int j)
{
	if ((data->p_state) == 0)
	{
		fill_player_down (data, i, j);
		(data->p_state) = 1;
	}
	else if ((data->p_state) == 1)
	{
		fill_player_down2 (data, i, j);
		(data->p_state) = 2;
	}
	else if ((data->p_state) == 2)
	{
		fill_player_down1 (data, i, j);
		(data->p_state) = 0;
	}
}

void	sprite_player(t_dataStruct *data, int i, int j)
{
	if ((data->p_dstate) == 'R')
		sprite_player_right (data, i, j);
	else if ((data->p_dstate) == 'L')
		sprite_player_left (data, i, j);
	else if ((data->p_dstate) == 'U')
		sprite_player_up (data, i, j);
	else if ((data->p_dstate) == 'D')
		sprite_player_down (data, i, j);
}
