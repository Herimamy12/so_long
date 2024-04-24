/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_next_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:25:37 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/24 13:34:19 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collector_error(char **charmap, int length, int width)
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
		return (0);
	}
	return (count_collector);
}

int	exit_error(char **charmap, int length, int width)
{
	int	i;
	int	j;
	int	count_exit;

	i = 0;
	count_exit = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (charmap[i][j] == 'E')
				count_exit++;
			j++;
		}
		i++;
	}
	if (count_exit < 1 || 1 < count_exit)
	{
		ft_printf ("Exit error\n");
		return (42);
	}
	return (0);
}

int	find_pos_i(char **charmap, int length, int width, char set)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (charmap[i][j] == set)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_pos_y(char **charmap, int length, int width, char set)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (charmap[i][j] == set)
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
	if (check_the_path_error (map, ln, wdth, pos_i_a, pos_y_a))
		return (42);
	return (0);
}
