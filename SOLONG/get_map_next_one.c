/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_next_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:10:16 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/23 13:49:17 by nherimam         ###   ########.fr       */
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
					ft_printf ("Map error !\n");
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
					ft_printf ("Map error !\n");
					return (42);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	content_error(char **charmap, int length, int width)
{
	int	i;
	int	j;
	int	count_collector;

	i = 0;
	count_collector = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (charmap[i][j] == 'C')
				count_collector++;
			j++;
		}
		i++;
	}
	if (count_collector < 1)
	{
		ft_printf ("Nothing collector\n");
		return (42);
	}
	return (0);
}

int	map_border_content_error(char **charmap, int length, int width)
{
	if (border_top_bottom_error (charmap, length, width))
		return (42);
	if (border_left_right_error (charmap, length, width))
		return (42);
	if (content_error (charmap, length, width))
		return (42);
	return (0);
}
