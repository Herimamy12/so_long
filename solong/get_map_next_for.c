/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_next_for.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:36:55 by nherimam          #+#    #+#             */
/*   Updated: 2024/06/23 12:36:57 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_the_second_path_error(char **map, int i, int y)
{
	int	ln;
	int	wdth;

	ln = count_length_map (map);
	wdth = count_width_map (map);
	if (i < 0 || i >= ln || y < 0 || y > wdth)
		return ;
	if (map[y][i] == '1' || map[y][i] == '8')
		return ;
	map[y][i] = '8';
	check_the_second_path_error (map, i - 1, y);
	check_the_second_path_error (map, i + 1, y);
	check_the_second_path_error (map, i, y - 1);
	check_the_second_path_error (map, i, y + 1);
}
