#include "holberton.h"

/**
 * _printf - selects the correct function to print
 * @format: identifier to look for
 * @...: variable arguments
 * Return: length of the string
 */
int _printf(const char *format,...)
{
    va_list args;
    int len = 0;

    va_start(args, format);

    for (int i = 0; format[i]!= '\0'; i++)
    {
        if (format[i] == '%')
        {
            switch (format[++i])
            {
                case '':
                    len += printf_string(va_arg(args, char *));
                    break;
                case 'c':
                    len += printf_char(va_arg(args, int));
                    break;
                case '%':
                    len += printf_21();
                    break;
                case 'i':
                case 'd':
                    len += printf_int(va_arg(args, int));
                    break;
                case 'r':
                    len += printf_srev(va_arg(args, char *));
                    break;
                case 'R':
                    len += printf_rot13(va_arg(args, char *));
                    break;
                case 'b':
                    len += printf_bin(va_arg(args, int));
                    break;
                case 'u':
                    len += printf_unsigned(va_arg(args, unsigned int));
                    break;
                case 'o':
                    len += printf_oct(va_arg(args, int));
                    break;
                case 'x':
                    len += printf_hex(va_arg(args, int));
                    break;
                case 'X':
                    len += printf_HEX(va_arg(args, int));
                    break;
                case 'S':
                    len += printf_exclusive_string(va_arg(args, char *));
                    break;
                case 'p':
                    len += printf_pointer(va_arg(args, void *));
                    break;
                default:
                    _putchar('%');
                    len++;
                    break;
            }
        }
        else
        {
            _putchar(format[i]);
            len++;
        }
    }

    va_end(args);
    return len;
}