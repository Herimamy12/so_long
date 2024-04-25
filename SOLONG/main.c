/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:21:53 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/25 13:48:28 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_wmap_mlx	wmap_mlx;

	if (argc == 1)
		return (1);
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0)
		return (1);
	if (get_map_error (fd))
		return (1);
//	wmap_mlx.map = get_char_map (fd);
	wmap_mlx.mlx_ptr = mlx_init();
	wmap_mlx.win_ptr = mlx_new_window(wmap_mlx.mlx_ptr, 800, 500, "so_long");
	mlx_key_hook (wmap_mlx.win_ptr, check_key, &wmap_mlx);
	mlx_mouse_hook (wmap_mlx.win_ptr, check_mouse, &wmap_mlx);
	mlx_loop(wmap_mlx.mlx_ptr);
//	free_char_two_star (wmap_mlx.map);
	return (0);
}
