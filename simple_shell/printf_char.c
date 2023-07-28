#include <stdio.h>

typedef __builtin_va_list va_list;

int _printf(const char *format, va_list ap)
{
    int i = 0, j;
    char c;

    while (format[i])
    {
        if (format[i]!= '%')
        {
            _putchar(format[i]);
            i++;
            continue;
        }
        else if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    c = __builtin_va_arg(ap, int);
                    _putchar(c);
                    i++;
                    break;
                case '':
                    j = 0;
                    c = __builtin_va_arg(ap, char *);
                    while (c[j])
                    {
                        _putchar(c[j]);
                        j++;
                    }
                    i++;
                    break;
                // handle other format specifiers as needed
                default:
                    _putchar('%');
                    _putchar(format[i]);
                    i++;
                    break;
            }
        }
    }
    return i;
}