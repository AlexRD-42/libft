/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:26:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:26:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Outputs the character ’c’ to the specified file descriptor
// ft_strlen
void ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return;
	write(fd, &c, 1);
}