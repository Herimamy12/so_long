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

//#################################################################
//#################################################################
//#################################################################
//#################################################################
//#################################################################

// typedef struct s_data
// {
//     void *mlx_ptr;
//     void *win_ptr;
// } t_data;

// // Fonction appelée lors de la fermeture de la fenêtre
// int close_window(int keycode, t_data *data)
// {
// 	if (keycode == 0)
// 		return (0);
//     mlx_destroy_window(data->mlx_ptr, data->win_ptr); // Fermer la fenêtre
//     // Libérer d'autres ressources si nécessaire
//     exit(0); // Quitter le programme proprement
// }

// int main()
// {
//     t_data data;

//     // Initialisation de la minilibX
//     data.mlx_ptr = mlx_init();
//     data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Ma fenêtre");

//     // Associer la fonction close_window à l'événement de fermeture
//     mlx_hook(data.win_ptr, 17, 0, close_window, &data);

//     // Boucle principale du programme
//     mlx_loop(data.mlx_ptr);

//     return 0;
// }