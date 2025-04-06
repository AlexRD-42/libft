/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:43:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/06 20:43:29 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_info.h"
#include "ft_conversion.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

// Outputs the character ’c’ to the specified file descriptor
void ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return;
	write(fd, &c, 1);
}

// Outputs the string ’s’ to the specified file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	if (fd == -1 || s == NULL)
		return;
	write(fd, s, ft_strlen(s));	
}

// Outputs the string ’s’ to the specified file descriptor followed by a newline
void	ft_putendl_fd(char *s, int fd)
{
	if (fd == -1 || s == NULL)
		return;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// Outputs the integer ’n’ to the specified file descriptor.
void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (fd == -1)
		return;
	str = ft_itoa(n);
	if (str != NULL)
	{
		write(fd, str, ft_strlen(str));
		free(str);
	}
}