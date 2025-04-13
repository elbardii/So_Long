/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/13 17:12:03 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Outputs a single character to stdout */
static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Outputs an integer to stdout */
static void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

/* Simplified printf function that supports %d format specifier */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			ft_putnbr(va_arg(args, int));
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}
