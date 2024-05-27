/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_two_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:11:19 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:11:20 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	collector_error(char **map, int length, int width)
{
	int	i;
	int	j;
	int	countCollector;

	i = 0;
	countCollector = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (map[i][j] == 'C')
				countCollector++;
			j++;
		}
		i++;
	}
	if (countCollector < 1)
		return (42);
	return (0);
}

int	exit_error(char **map, int length, int width)
{
	int	i;
	int	j;
	int	countExit;

	i = 0;
	countExit = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (map[i][j] == 'E')
				countExit++;
			j++;
		}
		i++;
	}
	if (countExit < 1 || 1 < countExit)
		return (42);
	return (0);
}

int	find_pos_i(char **map, int length, int width, char set)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (map[i][j] == set)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_pos_y(char **map, int length, int width, char set)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (map[i][j] == set)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_collector_exit_error(char **map, int ln, int wdth)
{
	int	pos_i_a;
	int	pos_y_a;

	pos_i_a = find_pos_i(map, ln, wdth, 'P');
	pos_y_a = find_pos_y(map, ln, wdth, 'P');
	check_the_path_error (map, pos_i_a, pos_y_a);
	if (!collector_error (map, ln, wdth))
	{
		ft_printf ("Error\n");
		return (42);
	}
	return (0);
}
