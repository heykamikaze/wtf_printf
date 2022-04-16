/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:58:33 by nbenjami          #+#    #+#             */
/*   Updated: 2021/12/08 14:28:30 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbrhex(unsigned int n)
{
	int	len;

	len = nbrlenhex(n);
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbrhex(n * (-1));
	}
	else if (n >= 16)
	{
		ft_putnbrhex(n / 16);
		ft_putchar("0123456789abcdef"[n % 16]);
	}
	else
		ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

unsigned int	ft_putnbrhex_capital(unsigned int n)
{
	int	len;

	len = nbrlenhex(n);
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbrhex_capital(n * (-1));
	}
	else if (n >= 16)
	{
		ft_putnbrhex_capital(n / 16);
		ft_putchar("0123456789ABCDEF"[n % 16]);
	}
	else
		ft_putchar("0123456789ABCDEF"[n % 16]);
	return (len);
}

unsigned int	nbrlenhex(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
