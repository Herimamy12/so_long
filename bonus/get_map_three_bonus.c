/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_three_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:11:29 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:11:30 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_the_path_error(char **map, int i, int y)
{
	int	ln;
	int	wdth;

	ln = count_length_map (map);
	wdth = count_width_map (map);
	if (i < 0 || i >= ln || y < 0 || y > wdth)
		return ;
	if (map[y][i] == '1' || map[y][i] == 'X')
		return ;
	if (map[y][i] == 'd' || map[y][i] == 'E')
		return ;
	map[y][i] = 'X';
	check_the_path_error (map, i - 1, y);
	check_the_path_error (map, i + 1, y);
	check_the_path_error (map, i, y - 1);
	check_the_path_error (map, i, y + 1);
}

char	**ft_map_copy(char **map, int length, int width)
{
	int		i;
	int		j;
	char	**map_copy;

	map_copy = (char **)malloc(sizeof (char *) * (width + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < width)
	{
		map_copy[i] = (char *)malloc(sizeof (char) * (length + 1));
		if (!map_copy[i])
			return (NULL);
		j = 0;
		while (j < length && map[i][j])
		{
			map_copy[i][j] = map[i][j];
			j++;
		}
		map_copy[i][j] = '\0';
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	extension_error(char *file_name)
{
	char	*ext;

	ext = ft_strrchr (file_name, '.');
	if (!ext)
	{
		ft_printf ("Error\nExtension required\n");
		return (42);
	}
	if (!ft_strcmp (ext, ".ber") || !(file_name - ext))
	{
		ft_printf ("Error\nMap must be a name.ber\n");
		return (42);
	}
	return (0);
}

int	check_content(char set)
{
	if (set != 'P' && set != '1')
		if (set != 'E' && set != 'C')
			if (set != '0' && set != 'd')
				return (42);
	return (0);
}

int	content_error(char **map, int length, int width)
{
	int	i;
	int	j;

	i = 0;
	if (length == width)
	{
		ft_printf ("Error\nMap carre is't valide\n");
		return (42);
	}
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			if (check_content (map[i][j]))
			{
				ft_printf ("Error\nOther char detected\n");
				return (42);
			}
			j++;
		}
		i++;
	}
	return (0);
}
