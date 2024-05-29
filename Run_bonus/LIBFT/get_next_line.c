/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:19:35 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/26 10:00:03 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t BUFFS, size_t szofcar)
{
	char	*stash;
	size_t	i;

	i = 0;
	stash = (char *)malloc(BUFFS * szofcar);
	if (!stash)
		return (NULL);
	while (i < (BUFFS * szofcar))
	{
		stash[i] = '\0';
		i++;
	}
	return ((void *)stash);
}

char	*ft_restash(char *stash)
{
	int		i;
	int		j;
	char	*newstash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || stash[i + 1] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	newstash = ft_calloc(sizeof(char), (ft_strlen(stash) - i + 1));
	if (!newstash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		newstash[j++] = stash[i++];
	newstash[j] = '\0';
	free(stash);
	return (newstash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	stash = ft_createstash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = ft_createline(stash);
	stash = ft_restash(stash);
	return (line);
}

int	ft_strcmp(char *cmd, char *set)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0' && set[i] != '\0')
	{
		if (cmd[i] != set[i])
			return (0);
		i++;
	}
	if (set[i] != '\0' || cmd[i] != '\0')
		return (0);
	return (42);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	ptr = NULL;
	len = ft_strlen(s);
	while ((len) >= 0)
	{
		ptr = (char *)&s[len];
		if (s[len] == (char)c)
			return (ptr);
		len--;
	}
	return (0);
}
