/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:31:30 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/26 09:59:15 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7000
# endif

char	*ft_strjoin(char *stash, char *buff);
void	*ft_calloc(size_t BUFFS, size_t szofcar);
char	*ft_createstash(int fd, char *stash);
char	*ft_createline(char *stash);
char	*ft_restash(char *stash);
char	*get_next_line(int fd);
long	ft_atol(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_count_word(char const *s, char c);
int		ft_isdigit(int c);
int		ft_strcmp(char *cmd, char *set);
char	*ft_strdup(char *old, char *str);

#endif
