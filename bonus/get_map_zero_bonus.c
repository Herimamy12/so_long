/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_zero_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:10:33 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:10:35 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_length_map(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	if (i < 1)
		return (0);
	return (i);
}

int	count_width_map(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	if (i < 1)
		return (0);
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
	char	**map;

	tmp = NULL;
	line = get_next_line (fd);
	i = 0;
	while (line)
	{
		if (ft_strlen (line) < 2)
			line = ft_strdup (line, " \n");
		tmp = ft_strjoin (tmp, line);
		free (line);
		line = get_next_line (fd);
		i++;
	}
	map = ft_split (tmp, '\n');
	if (!map)
		return (0);
	free (tmp);
	free (line);
	return (map);
}

char	**get_map(int fd, char *file_name)
{
	int		width;
	int		length;
	char	**map;
	char	**map_copy;

	map = get_char_map (fd);
	if (!map)
	{
		ft_printf ("Error\n");
		return (NULL);
	}
	width = count_width_map (map);
	length = count_length_map (map);
	map_copy = ft_map_copy (map, length, width);
	if (extension_error (file_name))
		return (NULL);
	if (map_border_content_error (map, length, width))
	{
		free_char_two_star (map);
		free_char_two_star (map_copy);
		return (NULL);
	}
	free_char_two_star (map);
	return (map_copy);
}
