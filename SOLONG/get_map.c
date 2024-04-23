/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:43:51 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/23 13:50:25 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_length_map(char **charmap)
{
	int	i;

	i = 0;
	while (charmap[0][i] != '\n')
		i++;
	if (i < 3)
	{
		ft_printf ("Map error !\n");
		return (0);
	}
	return (i);
}

int	count_width_map(char **charmap)
{
	int		i;

	i = 0;
	while (charmap[i] != NULL)
		i++;
	if (i < 3)
	{
		ft_printf ("Map error !\n");
		return (0);
	}
	return (i);
}

void	free_char_two_star(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
		str = &(str[i]);
	}
}

char	**get_char_map(int fd)
{
	int		i;
	char	*line;
	char	**charmap;

	charmap = (char **) malloc (sizeof (char *) * 1024);
	if (!charmap)
		return (0);
	line = get_next_line (fd);
	i = 0;
	while (line)
	{
		charmap[i] = line;
		line = get_next_line (fd);
		i++;
	}
	return (charmap);
}

int	get_map_error(int fd)
{
	int		width;
	int		length;
	char	**charmap;

	charmap = get_char_map (fd);
	length = count_length_map (charmap);
	width = count_width_map (charmap);
	if (!length || !width)
		return (42);
	if (map_border_content_error (charmap, length, width))
		return (42);
	ft_printf ("length = %d, width = %d\n", length, width);
	return (0);
}
