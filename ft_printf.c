
#include "ft_printf.h"


int ft_printf(const char *format, ...)
{
	va_list args;
	int len;
	va_start(args, format);
	len = ft_printf(format, args);
	va_end(args);
	return len;
}

