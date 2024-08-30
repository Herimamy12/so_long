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

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_dataStruct
{
	int		count;
	int		p_state;
	char	p_dstate;
	int		d_state;
	int		c_state;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		player_i;
	int		player_j;
	int		enemy_i;
	int		enemy_j;
	char	mouv_text[20];
	char	*str_mouv;
}			t_dataStruct;

int		main(int argc, char **argv);
char	**get_map(int fd, char *file_name);
char	**get_char_map(int fd);
int		count_length_map(char **map);
int		count_width_map(char **map);
int		count_enemy(t_dataStruct *data);
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
int		enemy_error(char **map, int length, int width);
int		find_pos_i(char **map, int length, int width, char set);
int		find_pos_y(char **map, int length, int width, char set);
int		check_collector_exit_error(char **map, int ln, int wdth);
void	check_the_path_error(char **map, int i, int y);
void	check_the_second_path_error(char **map, int i, int y);
void	init_data(t_dataStruct *data);
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
void	fill_player_right1(t_dataStruct *p, int i, int j);
void	fill_player_right2(t_dataStruct *p, int i, int j);
void	fill_player_left1(t_dataStruct *p, int i, int j);
void	fill_player_left2(t_dataStruct *p, int i, int j);
void	fill_player_up1(t_dataStruct *p, int i, int j);
void	fill_player_up2(t_dataStruct *p, int i, int j);
void	fill_player_down1(t_dataStruct *p, int i, int j);
void	fill_player_down2(t_dataStruct *p, int i, int j);
void	fill_open_door(t_dataStruct *p, int i, int j);
void	fill_enemy0(t_dataStruct *p, int i, int j);
void	fill_enemy1(t_dataStruct *p, int i, int j);
void	fill_enemy2(t_dataStruct *p, int i, int j);
void	fill_enemy3(t_dataStruct *p, int i, int j);
void	fill_enemy4(t_dataStruct *p, int i, int j);
void	sprite_player(t_dataStruct *data, int i, int j);
void	sprite_enemy(t_dataStruct *data, int i, int j);
void	exit_window(t_dataStruct *data);
void	manage_to_leave(t_dataStruct *data);
void	move_up(t_dataStruct *data, int play_i, int play_j);
void	move_down(t_dataStruct *data, int play_i, int play_j);
void	move_right(t_dataStruct *data, int play_i, int play_j);
void	move_left(t_dataStruct *data, int play_i, int play_j);
int		handle_keypress(int keycode, t_dataStruct *data);
int		close_window(t_dataStruct *data);
int		check_door_close(int keycode, t_dataStruct *data, int i, int j);
void	ft_mouve_management(int keycode, t_dataStruct *data, int i, int j);
void	ft_open_door(t_dataStruct *p, int ln, int wdth);
void	move_in_place(t_dataStruct *data, int i, int j, int keycode);
void	manage_all_state(t_dataStruct *data);
void	sprite_collector(t_dataStruct *data, int i, int j);
void	fill_collector0(t_dataStruct *p, int i, int j);
void	fill_collector1(t_dataStruct *p, int i, int j);
void	fill_collector2(t_dataStruct *p, int i, int j);
void	fill_collector3(t_dataStruct *p, int i, int j);
void	move_the_enemy(t_dataStruct *data);
void	real_move(t_dataStruct *data, int i, int j);
void	check_other_path(t_dataStruct *data, int i, int j);

#endif
