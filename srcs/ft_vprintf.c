
#include "ft_printf.h"

int ft_vprintf(const char *format, va_list args)
{
	int i;
	int len;
	i = 0;
	len = 0;
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			i++;
			if(format[i] == 'c')
				len += ft_putchar(va_arg(args, int));
			//va_argで引数を取得し、putcharする
			else if(format[i] == 's')
				len += ft_putstr(va_arg(args, char *));
			else if(format[i] == 'd' || format[i] == 'i')
				len += ft_putnbr(va_arg(args, int));
			else if (format[i] == "%")
				len += i + 1;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	return(len);
}

