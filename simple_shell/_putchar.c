#include <stdio.h>

/**
 * putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success, the character written is returned.
 * On error, -1 is returned and errno is set appropriately.
 */
int putchar(int c)
{
    return (fputc(c, stdout));
}