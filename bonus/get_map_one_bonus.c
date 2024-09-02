/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_one_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:11:06 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:11:08 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	border_top_bottom_error(char **map, int length, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (i == 0 || i == (width - 1))
			{
				if (map[i][j] != '1')
				{
					ft_printf ("Error\nVerify your wall top or bottom\n");
					return (42);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	border_left_right_error(char **map, int length, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (j == 0 || j == (length - 1))
			{
				if (map[i][j] != '1')
				{
					ft_printf ("Error\nVerify your wall left or right\n");
					return (42);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	length_error(char **map, int length, int width)
{
	int	i;
	int	j;
	int	count_length;

	i = 0;
	while (i < width)
	{
		j = 0;
		count_length = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			count_length++;
			j++;
		}
		if (count_length != length)
		{
			ft_printf ("Error\nMap must be rectangular\n");
			return (42);
		}
		i++;
	}
	return (0);
}

int	player_error(char **map, int length, int width)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (map[i][j] == 'P')
				count_player++;
			j++;
		}
		i++;
	}
	if (count_player < 1 || 1 < count_player)
	{
		ft_printf ("Error\nNumber of player isn't one\n");
		return (42);
	}
	return (0);
}

int	map_border_content_error(char **map, int length, int width)
{
	if (content_error (map, length, width))
		return (42);
	if (border_top_bottom_error (map, length, width))
		return (42);
	if (border_left_right_error (map, length, width))
		return (42);
	if (length_error (map, length, width))
		return (42);
	if (player_error (map, length, width))
		return (42);
	if (collector_error (map, length, width))
	{
		ft_printf ("Error\nNo collector in the map\n");
		return (42);
	}
	if (exit_error (map, length, width) || enemy_error (map, length, width))
	{
		ft_printf ("Error\nNumber of exit isn't one\n");
		return (42);
	}
	if (check_collector_exit_error (map, length, width))
		return (42);
	return (0);
}
