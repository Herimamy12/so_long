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

	if (argc != 2)
	{
		ft_printf ("Error\nCheck your arg number\n");
		return (1);
	}
	if (extension_error (argv[1]))
		return (1);
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf ("Error\nCheck if your file is valide\n");
		return (1);
	}
	data.map = get_map (fd);
	if (data.map == NULL)
		return (1);
	init_data (&data);
	so_long_bonus (&data);
	return (0);
}
