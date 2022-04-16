/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:34:54 by nbenjami          #+#    #+#             */
/*   Updated: 2021/12/08 16:47:36 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				pars_args(char p, va_list arg_ptr);
int				ft_putchar(char c);
int				ft_putstr(char *k);
int				ft_putnbr(int n);
unsigned int	ft_putnbrhex(unsigned int n);
unsigned int	ft_putnbrhex_capital(unsigned int n);
int				ft_putpointer(unsigned long long n);
int				ft_printf(const char *n, ...);
int				nbrlen(int n);
unsigned int	ft_putnbrhex(unsigned int n);
unsigned int	nbrlenhex(unsigned int n);
unsigned int	ft_putnbr_u(unsigned int n);
int				nbrlenhex_p(unsigned long long n);
int				helper(unsigned long long n);

#endif
