/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:31:51 by nbenjami          #+#    #+#             */
/*   Updated: 2021/12/08 16:48:19 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *k)
{
	int	a;

	a = 0;
	if (!k)
		return (write (1, "(null)", 6));
	while (k[a] != '\0')
	{
		ft_putchar(k[a]);
		a++;
	}
	return (a);
}
