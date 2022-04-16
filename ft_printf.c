/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:35:44 by nbenjami          #+#    #+#             */
/*   Updated: 2021/12/08 16:55:47 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
int	ft_printf(const char *n, ...)
{
	va_list	arg_ptr;
	int		i;
	int		res;
	int		a;

	i = 0;
	res = 0;
	va_start(arg_ptr, n);
	while (n[i])
	{
		if (n[i] != '%')
		{
			write(1, &n[i], 1);
			res++;
		}
		else if (n[i++] == '%')
		{
			a = pars_args(n[i], arg_ptr);
			res = res + a;
		}
		i++;
	}
	va_end(arg_ptr);
	return (res);
}

int	pars_args(char p, va_list arg_ptr)
{
	if (p == 'c')
		return (ft_putchar(va_arg(arg_ptr, int)));
	if (p == 's')
		return (ft_putstr(va_arg(arg_ptr, char *)));
	if (p == 'd' || p == 'i')
		return (ft_putnbr(va_arg(arg_ptr, long int)));
	if (p == 'x')
		return (ft_putnbrhex(va_arg(arg_ptr, long long)));
	if (p == 'X')
		return (ft_putnbrhex_capital(va_arg(arg_ptr, long int)));
	if (p == '%')
		return (ft_putchar('%'));
	if (p == 'p')
	{
		return (ft_putpointer(va_arg(arg_ptr, unsigned long long)));
	}
	if (p == 'u')
		return (ft_putnbr_u(va_arg(arg_ptr, unsigned int)));
	return (0);
}

/* #include <stdio.h>
#include <limits.h>

int	main(void)
{	
	int a = 8;
	int c = printf(" %p %p \n", INT_MIN, INT_MAX);
	int b = ft_printf(" %p %p \n", INT_MIN, INT_MAX);
	printf(" ---- %d rl\n",  c - b);
	printf(" ---- %d my\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf("%u", -1);
	ft_printf("%u", -1);
	printf("%d rl\n", printf("%u", -1));
	printf("%d my\n", ft_printf("%u", -1));
}
int	main(void)
{
	int	a;
	a = -1;
	printf(" ---- %d rl\n", printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf(" ---- %d my\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
*/