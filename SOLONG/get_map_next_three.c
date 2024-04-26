/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_next_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:24:02 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/26 10:14:53 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map[y][i] = 'X';
	check_the_path_error (map, i - 1, y);
	check_the_path_error (map, i + 1, y);
	check_the_path_error (map, i, y - 1);
	check_the_path_error (map, i, y + 1);
}

char	**ft_map_copy(char **charmap, int length, int width)
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
		while (j < length)
		{
			map_copy[i][j] = charmap[i][j];
			j++;
		}
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
		return (42);
	if (!ft_strcmp (ext, ".ber"))
	{
		ft_printf ("Error\n");
		return (42);
	}
	return (0);
}
