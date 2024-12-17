#include "ft_printf.h"



int ft_putnbr(int n)
{
	int len;
	len = 0;
	char c;
	if(n == -2147483648)
		write(1, "-2147483648", 11);
	if(n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if(n >= 10)
		len += ft_putnbr(n / 10);
		//1桁になるまでputnbrを通し、nを文字にし続ける
	c = n % 10 + '0';
	len += ft_putchar(c);
	return(len);

}
