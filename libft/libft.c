/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:47:26 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/29 12:47:29 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *old, char *str)
{
	int		i;
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free (old);
	return (new);
}
