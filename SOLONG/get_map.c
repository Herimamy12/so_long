/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:43:51 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/22 12:43:53 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_length_map(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line (fd);
	if (!line)
		return (0);
	while (line[i] != '\n')
		i++;
	if (i < 3)
	{
		ft_printf ("Map Error\n");
		return (0);
	}
	return (i);
}

int	count_width_map(int fd)
{
	int		i;
	char	*line;

	i = 1;
	line = get_next_line (fd);
	if (!line)
		return (0);
	while (line)
	{
		i++;
		line = get_next_line (fd);
	}
	if (i < 3)
	{
		ft_printf ("Map Error\n");
		return (0);
	}
	return (i);
}

//int	map_content_error(int fd, int length, int width)

int	get_map_error(int fd)
{
	int	i;
	int	width;
	int	length;

	i = 0;
	length = count_length_map (fd);
	if (length == 0)
		return (42);
	width = count_width_map (fd);
	if (width == 00)
		return (42);
	// if (map_content_error (fd, length, width));
	// 	return (42);
	ft_printf ("length = %d\nwidth = %d\n", length, width);
	return (i);
}
