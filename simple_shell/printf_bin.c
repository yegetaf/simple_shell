#include "holberton.h"

/**
 * print_binary - prints a binary number.
 * @num: the number to print.
 * @width: the width of the output field.
 * @zero_pad: whether to pad with zeros.
 * @upper_case: whether to print in uppercase.
 *
 * Return: the number of characters printed.
 */
int print_binary(unsigned int num, int width, int zero_pad, int upper_case)
{
    int count = 0;
    int i;
    char c;

    for (i = 31; i >= 0; i--)
    {
        c = (num >> i) & 1;
        c += '0';
        if (upper_case)
        {
            c = toupper(c);
        }
        if (zero_pad || c!= '0')
        {
            _putchar(c);
            count++;
        }
        if (count == width)
        {
            break;
        }
    }

    return count;
}