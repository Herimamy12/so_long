/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:43:51 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/26 09:45:01 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_length_map(char **charmap)
{
	int	i;

	i = 0;
	while (charmap[0][i] != '\0')
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
	}
	free (str);
}

char	**get_char_map(int fd)
{
	int		i;
	char	*tmp;
	char	*line;
	char	**charmap;

	tmp = NULL;
	line = get_next_line (fd);
	i = 0;
	while (line)
	{
		tmp = ft_strjoin (tmp, line);
		free (line);
		line = get_next_line (fd);
		i++;
	}
	charmap = ft_split (tmp, '\n');
	if (!charmap)
		return (0);
	free (tmp);
	free (line);
	return (charmap);
}

char	**get_map_error(int fd)
{
	int		width;
	int		length;
	char	**charmap;
	char	**map_copy;

	charmap = get_char_map (fd);
	width = count_width_map (charmap);
	length = count_length_map (charmap);
	map_copy = ft_map_copy (charmap, length, width);
	if (!length || !width)
	{
		free_char_two_star (charmap);
		free_char_two_star (map_copy);
		return (NULL);
	}
	else if (map_border_content_error (charmap, length, width))
	{
		free_char_two_star (charmap);
		free_char_two_star (map_copy);
		return (NULL);
	}
	free_char_two_star (charmap);
	return (map_copy);
}
