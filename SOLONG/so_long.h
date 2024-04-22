#ifndef SO_LONG_H
# define SO_LONG_H

# include "../LIST/list.h"
# include "../LIBFT/libft.h"
# include "../PRINTF/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

int	get_map_error(int fd);
int	count_length_map(int fd);
int	count_width_map(int fd);

#endif