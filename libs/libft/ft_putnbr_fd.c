/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:25:13 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 02:42:47 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
		n *= -write(fd, "-", 1);
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd("0123456789"[n % 10], fd);
}
/*
int main(void)
{
    // Test different cases
    ft_putnbr_fd(42, 1);          // Regular positive number
    write(1, "\n", 1);
    
    ft_putnbr_fd(-42, 1);         // Negative number
    write(1, "\n", 1);
    
    ft_putnbr_fd(0, 1);           // Zero
    write(1, "\n", 1);
    
    ft_putnbr_fd(-2147483648, 1); // INT_MIN
    write(1, "\n", 1);
    
    ft_putnbr_fd(2147483647, 1);  // INT_MAX
    write(1, "\n", 1);
    
    return (0);
}
*/