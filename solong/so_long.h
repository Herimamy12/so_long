/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:19:14 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/30 13:15:32 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_wmap_mlx
{
	int		count;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}			t_wmap_mlx;

char	**get_char_map(int fd);
char	**get_map_error(int fd);
int		count_length_map(char **charmap);
int		count_width_map(char **charmap);
void	free_char_two_star(char **str);
int		extension_error(char *file_name);
char	**ft_map_copy(char **charmap, int length, int width);
int		check_content(char set);
int		content_error(char **charmap, int length, int width);
int		border_top_bottom_error(char **charmap, int length, int width);
int		border_left_right_error(char **charmap, int length, int width);
int		map_border_content_error(char **charmap, int length, int width);
int		player_error(char **charmap, int length, int width);
int		collector_error(char **charmap, int length, int width);
int		exit_error(char **charmap, int length, int width);
int		find_pos_i(char **charmap, int length, int width, char set);
int		find_pos_y(char **charmap, int length, int width, char set);
int		check_collector_exit_error(char **map, int ln, int wdth);
void	check_the_path_error(char **map, int i, int y);
void	check_the_second_path_error(char **map, int i, int y);
void	so_long(t_wmap_mlx *p);
void	fill_window(t_wmap_mlx *p, int ln, int wdth);
void	fill_player(t_wmap_mlx *p, int i, int j);
void	fill_wall(t_wmap_mlx *p, int i, int j);
void	fill_road(t_wmap_mlx *p, int i, int j);
void	fill_collector(t_wmap_mlx *p, int i, int j);
void	fill_exit(t_wmap_mlx *p, int i, int j);
void	exit_window(t_wmap_mlx *data);
void	move_up(t_wmap_mlx *data, int play_i, int play_j);
void	move_down(t_wmap_mlx *data, int play_i, int play_j);
void	move_left(t_wmap_mlx *data, int play_i, int play_j);
void	move_right(t_wmap_mlx *data, int play_i, int play_j);
int		handle_keypress(int keycode, t_wmap_mlx *data);
void	manage_to_leave(t_wmap_mlx *data);
int		close_window(t_wmap_mlx *data);
void	fill_player_right(t_wmap_mlx *p, int i, int j);
void	fill_player_left(t_wmap_mlx *p, int i, int j);
void	fill_player_up(t_wmap_mlx *p, int i, int j);
void	fill_player_down(t_wmap_mlx *p, int i, int j);
void	ft_open_door(t_wmap_mlx *p, int ln, int wdth);
void	fill_open_door(t_wmap_mlx *p, int i, int j);
void	ft_mouve_management(int keycode, t_wmap_mlx *data, int i, int j);
int		check_door_close(int keycode, t_wmap_mlx *data, int i, int j);

#endif
