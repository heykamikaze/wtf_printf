#include <stdarg.h>
#include <unistd.h>


int	counter = 0;

// int	nbrlen(int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n < 0)
// 	{
// 		n = -n;
// 		len++;
// 	}
// 	while (n)
// 	{
// 		n = n / 10;
// 		len++;
// 	}
// 	return (len);
// }

// int	ft_putnbr(int n)
// {
// 	int	len;

// 	len = nbrlen(n);
// 	if (n == -2147483648)
// 	{
// 		write (1, "-2147483648", 11);
// 		return (11);
// 	}
// 	else if (n < 0)
// 	{
// 		ft_putchar('-');
// 		ft_putnbr(n * (-1));
// 	}
// 	else if (n >= 10)
// 	{
// 		ft_putnbr(n / 10);
// 		ft_putchar(n % 10 + '0');
// 	}
// 	else
// 		ft_putchar(n + 48);
// 	return (len);
// }

void	ft_putnbr(long dig, int len, char *sign) {
	if (dig >= len)
		ft_putnbr(dig/len, len, sign);
	write (1, &sign[dig % len], 1);
	counter++;
}

// unsigned int	ft_putnbrhex(unsigned int n)
// {
// 	int	len;

// 	len = nbrlenhex(n);
// 	if (n < 0)
// 	{
// 		ft_putchar('-');
// 		ft_putnbrhex(n * (-1));
// 	}
// 	else if (n >= 16)
// 	{
// 		ft_putnbrhex(n / 16);
// 		ft_putchar("0123456789abcdef"[n % 16]);
// 	}
// 	else
// 		ft_putchar("0123456789abcdef"[n % 16]);
// 	return (len);
// }

int	ft_printf(const char *format, ...) {
	va_list	ap;
	va_start(ap, format);
	while (*format) {
		if (*format == '%') {
			format++;
			if (*format == 's') {
				int	len = 0;
				char *str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len])
					len++;
				counter += len;
				write(1, str, len);
			}
			else if (*format == 'd') {
				int d = va_arg(ap, int);
				if (d < 0) {
					write(1, "-", 1);
					counter++;
					d = -d;
				}
				ft_putnbr(d, 10, "0123456789");
			}
			else if (*format == 'x') {
				int x = va_arg(ap, unsigned);
				ft_putnbr(x, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			counter += write(1, format++, 1);
	}
	va_end(ap);
	return(counter);
}

int	main(void)
{
	int original;
	int	mine;
	original = printf("Look who failed %s\n", "again");
	mine = ft_printf("Look who failed %s\n", "again");
	printf("Original ----- %d\nMine ----- %d", original, mine);
	original = printf("Look who failed %d\n times", 9);
	mine = ft_printf("Look who failed %d\n times", 9);
	printf("Original ----- %d\nMine ----- %d", original, mine);
}