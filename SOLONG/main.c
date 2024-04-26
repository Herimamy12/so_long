/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:21:53 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/26 13:54:10 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_wmap_mlx *pwmp)
{
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	pwmp->mlx_ptr = mlx_init();
	if (!pwmp->mlx_ptr)
		return ;
	pwmp->win_ptr = mlx_new_window(pwmp->mlx_ptr, 900, 550, "so_long");
	if (!pwmp->win_ptr)
		return ;
	ig_w = 50;
	ig_l = 50;
	ig_p = mlx_xpm_file_to_image (pwmp->mlx_ptr, "./prs/prs0.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (pwmp->mlx_ptr, pwmp->win_ptr, ig_p, 0, 0);
	mlx_destroy_image (pwmp->mlx_ptr, ig_p);
	ig_p = mlx_xpm_file_to_image (pwmp->mlx_ptr, "./prs/road.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (pwmp->mlx_ptr, pwmp->win_ptr, ig_p, 0, 50);
	mlx_destroy_image (pwmp->mlx_ptr, ig_p);
	ig_p = mlx_xpm_file_to_image (pwmp->mlx_ptr, "./prs/wall.xpm", &ig_w, &ig_l);
	mlx_put_image_to_window (pwmp->mlx_ptr, pwmp->win_ptr, ig_p, 50, 0);
	mlx_destroy_image (pwmp->mlx_ptr, ig_p);
	mlx_key_hook (pwmp->win_ptr, check_key, pwmp);
	mlx_mouse_hook (pwmp->win_ptr, check_mouse, pwmp);
	mlx_loop(pwmp->mlx_ptr);
}

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
