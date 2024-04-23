/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:19:14 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/23 13:50:13 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../LIST/list.h"
# include "../LIBFT/libft.h"
# include "../PRINTF/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

char	**get_char_map(int fd);
int		get_map_error(int fd);
int		count_length_map(char **charmap);
int		count_width_map(char **charmap);
void	free_char_two_star(char **str);
int		border_top_bottom_error(char **charmap, int length, int width);
int		border_left_right_error(char **charmap, int length, int width);
int		map_border_content_error(char **charmap, int length, int width);
int		content_error(char **charmap, int length, int width);

#endif
