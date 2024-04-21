/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:36:16 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/08 13:36:19 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && (s[i] != c))
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

char	*ft_strjoin(char *stash, char *buff)
{
	size_t	i;
	char	*str;
	size_t	ls1;
	size_t	ls2;

	ls1 = ft_strlen(stash);
	ls2 = ft_strlen(buff);
	str = ft_calloc(sizeof(char), (ls2 + ls1 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ls1)
	{
		str[i] = stash[i];
		i++;
	}
	i = 0;
	while (i < ls2)
	{
		str[i + ls1] = buff[i];
		i++;
	}
	str[i + ls1] = '\0';
	free(stash);
	return (str);
}

char	*ft_createstash(int fd, char *stash)
{
	int		nbytes;
	char	*buff;

	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nbytes = 1;
	while (!ft_strchr(stash, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[nbytes] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_createline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i] || stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
