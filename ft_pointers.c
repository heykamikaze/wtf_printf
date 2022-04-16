/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:37:07 by nbenjami          #+#    #+#             */
/*   Updated: 2021/12/08 14:27:33 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long long n)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	len += helper(n);
	return (len);
}

int	helper(unsigned long long n)
{
	int	p;

	p = nbrlenhex_p(n);
	if (n >= 16)
	{
		helper(n / 16);
		ft_putchar("0123456789abcdef"[n % 16]);
	}
	else
		ft_putchar("0123456789abcdef"[n % 16]);
	return (p);
}

int	nbrlenhex_p(unsigned long long n)
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
