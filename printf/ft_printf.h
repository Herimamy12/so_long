/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:39:15 by nherimam          #+#    #+#             */
/*   Updated: 2024/03/24 16:39:17 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int	ft_printf(const char *str, ...);
int	ft_check(char c, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putaddress(unsigned long nb);
int	ft_putunsigned(unsigned int nb);
int	ft_printaddress(unsigned long nb);
int	ft_puthexa(unsigned int nb, char c);
int	ft_putlist(t_list *lst);

#endif
