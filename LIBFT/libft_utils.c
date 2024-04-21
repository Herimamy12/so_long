/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:31:21 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/08 09:31:22 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ('-' == nptr[i] || nptr[i] == '+')
	{
		if ('-' == nptr[i])
			sign *= -1;
		i++;
	}
	if (!('0' <= nptr[i] && nptr[i] <= '9'))
		return (0);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		nb *= 10;
		nb += (nptr[i] - '0');
		i++;
	}
	nb *= sign;
	return (nb);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lens;
	char	*str;

	lens = ft_strlen (s) - start;
	if (lens >= len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * (lens + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start++];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	if (!tmp)
		return (NULL);
	while (*tmp)
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
	}
	if (c == '\0')
		return (tmp);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**str;

	str = (char **)malloc(sizeof (char *) * (ft_count_word (s, c) + 1));
	if (!s || !str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (ft_strchr (s, c))
				len = ft_strchr (s, c) - s;
			else
				len = ft_strlen (s);
			str[i++] = ft_substr (s, 0, len);
			s += len;
		}
	}
	str[i] = NULL;
	return (str);
}
