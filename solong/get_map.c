/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:43:51 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/28 13:52:22 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_length_map(char **charmap)
{
	int	i;

	i = 0;
	while (charmap[0][i] != '\0')
		i++;
	if (i < 1)
		return (0);
	return (i);
}

int	count_width_map(char **charmap)
{
	int		i;

	i = 0;
	while (charmap[i] != NULL)
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
	char	**charmap;

	tmp = NULL;
	line = get_next_line (fd);
	i = 0;
	while (line)
	{
		if (ft_strlen (line) < 1)
			line = ft_strdup (line, " \n");
		tmp = ft_strjoin (tmp, line);
		free (line);
		line = get_next_line (fd);
		i++;
	}
	charmap = ft_split (tmp, '\n');
	free (tmp);
	free (line);
	if (!charmap)
		return (NULL);
	return (charmap);
}

char	**get_map_error(int fd)
{
	int		width;
	int		length;
	char	**charmap;
	char	**map_copy;

	charmap = get_char_map (fd);
	if (!charmap)
	{
		ft_printf ("Error\nMake sure your map is't empty\n");
		return (NULL);
	}
	width = count_width_map (charmap);
	length = count_length_map (charmap);
	map_copy = ft_map_copy (charmap, length, width);
	if (map_border_content_error (charmap, length, width))
	{
		free_char_two_star (charmap);
		free_char_two_star (map_copy);
		return (NULL);
	}
	free_char_two_star (charmap);
	return (map_copy);
}
