#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int ft_putstr(char *str){
	int i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str && str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_nbrlen(int num){
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
	return (acc);
}
// int	ft_putnbr(int n){
// 	char	c;
// 	int nbrlen = ft_nbrlen(n);
//     // printf("%d\n", nbrlen);
// 	if (n < 0 && n > -2147483648)
// 	{
// 		n = -n;
// 		write(1 , "-", 1);
// 	}
// 	if (n > 9 && n <= 2147483647)
// 	{
// 		ft_putnbr(n / 10);
// 		write(1 , &c, 1);
// 		c = n % 10 + '0';
// 	}
// 	c = n % 10 + '0';
// 	write(1 , &c, 1);
// 	if (n == -2147483648)
// 		write(1 , "-2147483648", 11);
// 	return (nbrlen);
// }

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	len;

	len = ft_nbrlen(n);
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + 48);
	return (len);
}

int	ft_nbrbase_len(unsigned int num){
	int acc = 0;
	if (num < 0)
		acc++;
	if (num == 0)
		acc++;
	while (num)
	{
		acc++;
		num = num / 16;
	}
	return (acc);
}
int	ft_putnbr_base(unsigned int num, char *base){
	int len = ft_nbrbase_len(num);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 0 && num <= 15)
		write(1, &base[num % 16], 1);
	if (num > 15)
	{
		ft_putnbr_base(num / 16, base);
		write(1, &base[num % 16], 1);
	}
	return (len);
}
int ft_parse_args(char c, va_list args){
	if (c == 's')
		return  ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		return ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		return ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	return (0);
}
int	ft_printf(char *prm, ...){
	va_list	args;
	int res = 0;
	va_start(args, prm);
	while (prm && *prm)
	{
		if (*prm != '%')
			write(1, prm, 1);
		if (*prm == '%')
			res += ft_parse_args(*(++prm), args);
		else
			res++;
		prm++;
	}
	va_end(args);
	return (res);
}
#include <stdio.h>
int main()
{
	printf("test int\n\n");
	// int a = ft_printf("-->%d<--\n", 1324);
	// int b = printf("-->%d<--\n", 1324);
	// printf("-->differ %d<--\n\n", a - b);
    // int a = ft_printf("-->%d<--\n", 135624);
	// int b = printf("-->%d<--\n", 135624);
	// printf("-->differ %d<--\n\n", a - b);
	// int a = ft_printf("-->%d<--\n", 2147483649);
	// int b = printf("-->%d<--\n", 2147483649);
	// printf("-->differ %d<--\n\n", a - b);
	// int a = ft_printf("-->%d<--\n", UINT_MAX);
	// int b = printf("-->%d<--\n", UINT_MAX);
	// printf("-->differ %d<--\n\n", a - b);
	// int a = ft_printf("-->%d<--\n", LONG_MAX - 1);
	// int b = printf("-->%d<--\n", LONG_MAX - 1);
	// printf("-->differ %d<--\n\n", a - b);
	// int a = ft_printf("-->%d<--\n", LLONG_MAX);
	// int b = printf("-->%d<--\n", LLONG_MAX);
	// printf("-->differ %d<--\n\n", a - b);
	int a = ft_printf("-->%d<--\n", ULONG_MAX);
	int b = printf("-->%d<--\n", ULONG_MAX);
	printf("-->differ %d<--\n\n", a - b);

	// a = ft_printf("-->%d<--\n", 0);
	// b = printf("-->%d<--\n", 0);
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%d<--\n", LONG_MIN);
	// b = printf("-->%d<--\n", LONG_MIN);
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%d<--\n", LLONG_MIN);
	// b = printf("-->%d<--\n", LLONG_MIN);
	// printf("-->differ %d<--\n\n", a - b);
	
	// a = ft_printf("-->%d %d %d<--\n", UINT_MAX , LONG_MIN , LLONG_MIN);
	// b = printf("-->%d %d %d<--\n", UINT_MAX, LONG_MIN , LLONG_MIN);
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%d<--\n", LONG_MAX - 1);
	// b = printf("-->%d<--\n", LONG_MAX - 1);
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%d<--\n", LLONG_MAX);
	// b = printf("-->%d<--\n", LLONG_MAX);
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%d<--\n", "ULONG_MAX");
	// b = printf("-->%d<--\n", "ULONG_MAX");
	// printf("-->differ %d<--\n\n", a - b);

	// printf("\ntest string\n\n");
	// a = ft_printf("-->%s<--\n", "ququ");
	// b = printf("-->%s<--\n", "ququ");
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%s<--\n", "");
	// b = printf("-->%s<--\n", "");
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%s<--\n", "1");
	// b = printf("-->%s<--\n", "1");
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%s<--\n", " ");
	// b = printf("-->%s<--\n", " ");
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%s<--\n", NULL);
	// b = printf("-->%s<--\n", NULL);
	// printf("-->differ %d<--\n\n", a - b);

	// printf("\ntest xxx\n\n");
	// a = ft_printf("-->%x<--\n", 1343);
	// b = printf("-->%x<--\n", 1343);
	// printf("-->differ %d<--\n\n", a - b);
	// a = ft_printf("-->%x<--\n", 0);
	// b = printf("-->%x<--\n", 0);
	// printf("-->differ %d<--\n", a - b);
	// a = ft_printf("-->%x<--\n", 2147483647);
	// b = printf("-->%x<--\n", 2147483647);
	// printf("-->differ %d<--\n\n", a - b);
}