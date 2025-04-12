/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:23:42 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 02:14:02 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	while (s && *s)
		write(fd, s++, 1);
}
/*
int	main(void)
{	
	ft_putstr_fd("Hello, world!\n", 1); 

	return (0);
}
*/
