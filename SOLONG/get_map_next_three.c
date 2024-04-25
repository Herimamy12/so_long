/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_next_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:24:02 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/25 09:41:01 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_the_path_error(char **map, int ln, int wdth, int i, int y)
{
	if (i < 0  || i >= ln || y < 0 || y > wdth )
		return ;
	if (map[y][i] == '1' || map[y][i] == 'X')
		return ;
	map[y][i] = 'X';
	check_the_path_error (map, ln, wdth, i - 1, y);
	check_the_path_error (map, ln, wdth, i + 1, y);
	check_the_path_error (map, ln, wdth, i, y - 1);
	check_the_path_error (map, ln, wdth, i, y + 1);
}
