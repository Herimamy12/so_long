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

int	main(int argc, char **argv)
{
	int				fd;
	t_dataStruct	data;

	data.count = 0;
	data.p_state = 0;
	data.p_Dstate = 0;
	data.d_state = 0;
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0 || argc != 2)
	{
		ft_printf ("Error\n");
		return (1);
	}
	data.map = get_map (fd, argv[1]);
	if (data.map == NULL)
		return (1);
	so_long_bonus (&data);
	return (0);
}
