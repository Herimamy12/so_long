/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_next_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:10:16 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/30 13:16:22 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	border_top_bottom_error(char **charmap, int length, int width)
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
				if (charmap[i][j] != '1')
				{
					ft_printf ("Error\n");
					return (42);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	border_left_right_error(char **charmap, int length, int width)
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
				if (charmap[i][j] != '1')
				{
					ft_printf ("Error\n");
					return (42);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	length_error(char **charmap, int length, int width)
{
	int	i;
	int	j;
	int	count_length;

	i = 0;
	while (i < width)
	{
		j = 0;
		count_length = 0;
		while (charmap[i][j] != '\n' && charmap[i][j] != '\0')
		{
			count_length++;
			j++;
		}
		if (count_length != length)
		{
			ft_printf ("Error\n");
			return (42);
		}
		i++;
	}
	return (0);
}

int	player_error(char **charmap, int length, int width)
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
			if (charmap[i][j] == 'P')
				count_player++;
			j++;
		}
		i++;
	}
	if (count_player < 1 || 1 < count_player)
	{
		ft_printf ("Error\n");
		return (42);
	}
	return (0);
}

int	map_border_content_error(char **charmap, int length, int width)
{
	if (content_error (charmap, length, width))
		return (42);
	if (border_top_bottom_error (charmap, length, width))
		return (42);
	if (border_left_right_error (charmap, length, width))
		return (42);
	if (length_error (charmap, length, width))
		return (42);
	if (player_error (charmap, length, width))
		return (42);
	if (collector_error (charmap, length, width))
	{
		ft_printf ("Error\n");
		return (42);
	}
	if (exit_error (charmap, length, width))
	{
		ft_printf ("Error\n");
		return (42);
	}
	if (check_collector_exit_error (charmap, length, width))
		return (42);
	return (0);
}
