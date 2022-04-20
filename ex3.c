#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int ft_putstr(char *str)
{
	int i = 0;
	if (!str)
		return (write(1, "(null)", 11));
	while (str && str[i])
		write(1, &str[i++], 1);
	return(i);
}


int	ft_nbrlen(int num)
{
	int acc = 0;
	if (num == 0)
		acc++;
	if (num < 0)
		acc++;
	while (num)
	{
		acc++;
		num = num / 10;
	}
	return(acc);
}

int	ft_nbrlen_base(unsigned int num)
{
	int acc = 0;
	if (num == 0)
		acc++;
	while (num)
	{
		acc++;
		num  = num / 16;
	}
	return(acc);
}


int ft_putnbr_base(unsigned int num, char *base)
{
	int len = ft_nbrlen_base(num);
	if (num >= 0 && num <= 15)
		write(1, &base[num % 16], 1);
	if (num > 15)
	{
		ft_putnbr_base(num / 16, base);
		write(1, &base[num % 16], 1);
	}
	return(len);
}

int ft_putnbr(int num)
{
	int len = ft_nbrlen(num);
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 1);
		return(11);
	}
	if (num < 0)
	{
		ft_putchar('-');
		ft_putnbr(num * (-1));
	}
	else if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else 
		ft_putchar(num + 48);
	return (len);
}	

int	ft_pars_args(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	return(0);
}

int	ft_printf(char *prm, ...)
{
	va_list args;
	int res = 0;
	va_start(args, prm);
	while (prm && *prm)
	{
		if (*prm != '%')
			write(1, prm, 1);
		if (*prm == '%')
			res += ft_pars_args(*(++prm), args);
		else
			res++;
		prm++;
	}
	va_end(args);
	return (res);
}

int	main(void)
{
	int a = ft_printf("%x\n", 0);
	int b = printf("%x\n", 0);
	int d = a - b;
	printf("differ %d\n", d);
}