/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:13:32 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:13:33 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_data(t_dataStruct *data)
{
	data->count = 0;
	data->p_state = 0;
	data->p_dstate = 'R';
	data->d_state = 0;
	data->c_state = 0;
}

int	main(int argc, char **argv)
{
	int				fd;
	t_dataStruct	data;

	fd = open (argv[1], O_RDONLY);
	if (fd <= 0 || argc != 2)
	{
		ft_printf ("Error\n");
		return (1);
	}
	data.map = get_map (fd, argv[1]);
	if (data.map == NULL)
		return (1);
	init_data (&data);
	so_long_bonus (&data);
	return (0);
}


/*#include <stdio.h>

int main(int argc, char **argv)
{
    void *mlx_ptr;
    void *win_ptr;
    int x = 100;
    int y = 200;
    int color = 0xFF0000; // Rouge
    int score = 42;
    char score_texte[20]; // Assurez-vous que la taille est suffisante

    // Initialisation de MiniLibX
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return 1;

    // Création d'une fenêtre
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Ma fenêtre");
    if (!win_ptr)
        return 1;

    // Créez la chaîne de caractères avec le score
    char *texte = "Score : %d";
    snprintf(score_texte, sizeof(score_texte), texte, score);

    // Affichage de la chaîne de caractères
    mlx_string_put(mlx_ptr, win_ptr, x, y, color, score_texte);

    // Boucle principale pour afficher la fenêtre
    mlx_loop(mlx_ptr);

    // Nettoyage
    mlx_destroy_window(mlx_ptr, win_ptr);
    return 0;
    (void)argc;
    (void)argv;
}
*/