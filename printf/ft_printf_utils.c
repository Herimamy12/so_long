/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:39:34 by nherimam          #+#    #+#             */
/*   Updated: 2024/03/24 16:39:35 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	valr;

	valr = 0;
	if (nb == -2147483648)
		return (ft_putstr ("-2147483648"));
	if (nb < 0)
	{
		valr += ft_putchar ('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		valr += ft_putnbr (nb / 10);
		valr += ft_putnbr (nb % 10);
	}
	else
		valr += ft_putchar (nb + '0');
	return (valr);
}

int	ft_printaddress(unsigned long nb)
{
	int	valr;

	valr = 0;
	if (nb > 15)
	{
		valr += ft_printaddress (nb / 16);
		valr += ft_printaddress (nb % 16);
	}
	else if (nb > 9)
		valr += ft_putchar (nb - 10 + 'a');
	else
		valr += ft_putchar (nb + '0');
	return (valr);
}

int	ft_putaddress(unsigned long nb)
{
	int	valr;

	valr = 0;
	if (!nb)
		return (ft_putstr ("(nil)"));
	nb = (unsigned long)nb;
	valr += ft_putstr ("0x");
	valr += ft_printaddress (nb);
	return (valr);
}

int	ft_puthexa(unsigned int nb, char c)
{
	int	valr;

	valr = 0;
	nb = (unsigned int)nb;
	if (nb > 15)
	{
		valr += ft_puthexa (nb / 16, c);
		valr += ft_puthexa (nb % 16, c);
	}
	else if (nb > 9)
	{
		if (c == 'x')
			valr += ft_putchar (nb - 10 + 'a');
		else
			valr += ft_putchar (nb - 10 + 'A');
	}
	else
		valr += ft_putchar (nb + '0');
	return (valr);
}

int	ft_putunsigned(unsigned int nb)
{
	int	valr;

	valr = 0;
	nb = (unsigned int)nb;
	if (nb > 9)
	{
		valr += ft_putunsigned (nb / 10);
		valr += ft_putunsigned (nb % 10);
	}
	else
		valr += ft_putchar (nb + '0');
	return (valr);
}
