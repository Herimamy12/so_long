/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_next_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:24:02 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/24 13:45:47 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_the_path_error(char **map, int ln, int wdth, int i, int y)
{
	if (i < 0  || i >= ln || y < 0 || y > wdth || map[y][i] != '0')
		return (42);
	else
	{
		map[y][i] = 'n';
		check_collector_exit_error (map, j + 1, i, )
	}
}
