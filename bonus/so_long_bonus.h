/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:11:46 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/26 17:11:47 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../LIST/list.h"
# include "../LIBFT/libft.h"
# include "../PRINTF/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_dataStruct
{
	int		count;
	int		p_state;
	int		p_Dstate;
	int		d_state;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}			t_dataStruct;

int		main(int argc, char **argv);
char	**get_map(int fd, char *fileName);
char	**get_char_map(int fd);
int		count_length_map(char **map);
int		count_width_map(char **map);
void	free_char_two_star(char **str);
int		extension_error(char *file_name);
char	**ft_map_copy(char **map, int length, int width);
int		check_content(char set);
int		content_error(char **map, int length, int width);
int		border_top_bottom_error(char **map, int length, int width);
int		border_left_right_error(char **map, int length, int width);
int		map_border_content_error(char **map, int length, int width);
int		player_error(char **map, int length, int width);
int		collector_error(char **map, int length, int width);
int		exit_error(char **map, int length, int width);
int		find_pos_i(char **map, int length, int width, char set);
int		find_pos_y(char **map, int length, int width, char set);
int		check_collector_exit_error(char **map, int ln, int wdth);
void	check_the_path_error(char **map, int i, int y);
void	so_long_bonus(t_dataStruct *data);
void	fill_window(t_dataStruct *p, int ln, int wdth);
void	fill_player(t_dataStruct *p, int i, int j);
void	fill_wall(t_dataStruct *p, int i, int j);
void	fill_road(t_dataStruct *p, int i, int j);
void	fill_collector(t_dataStruct *p, int i, int j);
void	fill_exit(t_dataStruct *p, int i, int j);
void	fill_player_right(t_dataStruct *p, int i, int j);
void	fill_player_left(t_dataStruct *p, int i, int j);
void	fill_player_up(t_dataStruct *p, int i, int j);
void	fill_player_down(t_dataStruct *p, int i, int j);
void	fill_open_door(t_dataStruct *p, int i, int j);

#endif
