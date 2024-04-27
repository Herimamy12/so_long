/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herimamy <herimamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:21:53 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/26 22:53:47 by herimamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_wmap_mlx *p)
{
	int		ln;
	int		wdth;
	int		ig_w;
	int		ig_l;
	void	*ig_p;

	p->mlx_ptr = mlx_init();
	if (!p->mlx_ptr)
		return ;
	ig_w = 50;
	ig_l = 50;
	ln = count_length_map (p->map);
	wdth = count_width_map (p->map);
	p->win_ptr = mlx_new_window(p->mlx_ptr, ln * 50, wdth * 50, "so_long");
	if (!p->win_ptr)
		return ;
	for (int i = 0; i < wdth; i++)
	{
		for (int j = 0; j < ln; j++)
		{
			if (p->map[i][j] == 'P')
			{
				ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/prs0.xpm", &ig_w, &ig_l);
				mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
				mlx_destroy_image (p->mlx_ptr, ig_p);
			}
			else if (p->map[i][j] == '1')
			{
				ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/wall.xpm", &ig_w, &ig_l);
				mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
				mlx_destroy_image (p->mlx_ptr, ig_p);
			}
			
			else
			{
				ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/road.xpm", &ig_w, &ig_l);
				mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, j * 50, i * 50);
				mlx_destroy_image (p->mlx_ptr, ig_p);
			}
		}
	}
	// ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/prs0.xpm", &ig_w, &ig_l);
	// mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, 0, 0);
	// mlx_destroy_image (p->mlx_ptr, ig_p);
	// ig_p = mlx_xpm_file_to_image (p->mlx_ptr, "./i/road.xpm", &ig_w, &ig_l);
	// mlx_put_image_to_window (p->mlx_ptr, p->win_ptr, ig_p, 0, 50);
	// mlx_destroy_image (p->mlx_ptr, ig_p);
	mlx_key_hook (p->win_ptr, check_key, p);
	mlx_mouse_hook (p->win_ptr, check_mouse, p);
	mlx_loop(p->mlx_ptr);
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
