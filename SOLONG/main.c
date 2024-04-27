/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:21:53 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/27 13:39:35 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_wmap_mlx	wmap_mlx;

	if (argc == 1)
		return (1);
	if (extension_error (argv[1]))
		return (1);
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0)
		return (1);
	wmap_mlx.map = get_map_error (fd);
	if (wmap_mlx.map == NULL)
		return (1);
	so_long (&wmap_mlx);
	return (0);
}
