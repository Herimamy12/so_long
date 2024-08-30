/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:21:53 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/28 13:53:17 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_wmap_mlx	wmap_mlx;

	wmap_mlx.count = 0;
	if (argc != 2)
	{
		ft_printf ("Error\n");
		return (1);
	}
	if (extension_error (argv[1]))
		return (1);
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0)
		return (1);
	wmap_mlx.map = get_map_error (fd);
	if (wmap_mlx.map == NULL)
		return (1);
	ft_printf ("mouv = %d\n", wmap_mlx.count);
	so_long (&wmap_mlx);
	return (0);
}
