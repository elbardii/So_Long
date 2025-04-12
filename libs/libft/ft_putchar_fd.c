/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:22:54 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 02:12:35 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

#include <fcntl.h>
int main()
{
	int fd = open("ismail1.text", O_WRONLY | O_RDONLY , 0644);
	// int fd = open("ismail.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('B', fd);
}

/*
int	main(void)
{

	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);


	ft_putchar_fd('B', 2);
	ft_putchar_fd('\n', 2);

	return (0);
}
*/
