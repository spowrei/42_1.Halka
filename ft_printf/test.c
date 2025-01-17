#include <stdio.h>
#include <stdarg.h>

void simple_printf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	while (*fmt != '\0')
	{
		if (*fmt == 'd')
		{
			int i = va_arg(args, int);
			printf("%d\n", i);
		}
		else if (*fmt == 'c')
		{
			int c = va_arg(args, int);
			printf("%c\n", c);
		}
		else if (*fmt == 'f')
		{
			double d = va_arg(args, double);
			printf("%f\n", d);
		}
		++fmt;
	}

	va_end(args);
}

#include <stdio.h>
int main()
{
	char c ='a';
	char *ptr = &c;

	printf(">> %p\n", ptr);
	return 0;
}